#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hicham Boutlalek");
MODULE_DESCRIPTION("Register a device nr. and implement some callback functions");

/*This fucntion is called, when the device file is opened*/
static int driver_open(struct inode *device_file, struct file *instance){
	printk("dev_nr - open was called!\n");
	return 0;
}

/*This fucntion is called, when the device file is closed*/
static int driver_close(struct inode *device_file, struct file *instance){
	printk("dev_nr - close was called!\n");
	return 0;
}

static struct file_operations fops = {
	.owner = THIS_MODULE,
	.open = driver_open,
	.release = driver_close
};

#define MYMAJOR 90

/* Function which is executed whenever the module is loaded into the kernel*/
static int __init ModuleInit (void){
	int retval;
	printk("The module 'Hello world' is loaded into the Kernel \n"); // Print to the linux kenel locks
	/* register device number*/
	retval = register_chrdev(MYMAJOR, "my_dev_nr", &fops);
	if(retval == 0){
		printk("dev_nr - registered Device number Major: %d, Minor: %d\n",MYMAJOR, 0);
	}
	else if(retval > 0){
		printk("dev_nr - registered Device number Major: %d, Minor: %d\n",retval>>20, retval&0xfffff);
	}
	else {
		printk("Could not register device number!\n");
		return -1;
	}
	return 0;
}

/* Function which is executed if the module is removed the kernel*/
static void __exit ModuleExit(void)
{
	unregister_chrdev(MYMAJOR, "my_dev_nr");
	printk("The module 'Hello workd' is removed"); 
}

module_init(ModuleInit);
module_exit(ModuleExit);
