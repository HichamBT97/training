#include <linux/module.h>
#include <linux/init.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Hicham Boutlalek");
MODULE_DESCRIPTION("A Hello world LKM");

/* Function which is executed whenever the module is loaded into the kernel*/
static int __init ModuleInit (void){
	printk("The module 'Hello workd' is loaded into the Kernel \n"); // Print to the linux kenel locks
	return 0;
}

/* Function which is executed if the module is removed the kernel*/
static void __exit ModuleExit(void)
{
	printk("The module 'Hello workd' is removed"); 
}

module_init(ModuleInit);
module_exit(ModuleExit);
