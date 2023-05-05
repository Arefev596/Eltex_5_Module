#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>
#include <linux/uaccess.h>
#include <linux/slab.h>
 
int len,temp;
 
char *msg;
 
ssize_t read_proc (struct file *filp, char *buf, size_t count, loff_t *offp )
{
    if(count > temp)
    {
        count = temp;
    }
    temp = temp - count;
    copy_to_user(buf, msg, count);
    if (count == 0)
        temp = len;
 
    return count;
}
 
ssize_t write_proc (struct file *filp, const char *buf, size_t count, loff_t *offp)
{
    copy_from_user(msg, buf, count);
    len = count;
    temp = len;
    return count;
}
 
struct proc_ops proc_fops = {
proc_read:
    read_proc,
proc_write:
    write_proc
};

/*struct proc_ops { // находится в директории /lib/modules/5.19.0-41-generic/build/include/linux/proc_fs.h
        unsigned int proc_flags;
        int     (*proc_open)(struct inode *, struct file *);
        ssize_t (*proc_read)(struct file *, char __user *, size_t, loff_t *);
        ssize_t (*proc_read_iter)(struct kiocb *, struct iov_iter *);
        ssize_t (*proc_write)(struct file *, const char __user *, size_t, loff_t *);
        
        loff_t  (*proc_lseek)(struct file *, loff_t, int);
        int     (*proc_release)(struct inode *, struct file *);
        __poll_t (*proc_poll)(struct file *, struct poll_table_struct *);
        long    (*proc_ioctl)(struct file *, unsigned int, unsigned long);
#ifdef CONFIG_COMPAT
        long    (*proc_compat_ioctl)(struct file *, unsigned int, unsigned long);
#endif
        int     (*proc_mmap)(struct file *, struct vm_area_struct *);
        unsigned long (*proc_get_unmapped_area)(struct file *, unsigned long, unsigned long, unsigned long, unsigned long);
};
*/
 
void create_new_proc_entry(void)  //use of void for no arguments is compulsory now
{
    proc_create ("hello", 0, NULL, &proc_fops);
    msg = kmalloc(10*sizeof(char), GFP_KERNEL);
}
 
 
int proc_init (void) {
    create_new_proc_entry();
    return 0;
}
 
void proc_cleanup(void) {
    remove_proc_entry("hello",NULL);
    kfree(msg);
}
 
MODULE_LICENSE("Eltex");
MODULE_AUTHOR("Arefev Alex");
MODULE_DESCRIPTION("A proc module");
module_init(proc_init);
module_exit(proc_cleanup);
