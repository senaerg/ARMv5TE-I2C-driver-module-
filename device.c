#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/i2c.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Developer");
MODULE_DESCRIPTION("An ARM9-adapted Linux Dummy I2C Core Module");
MODULE_VERSION("1.0");

static int dummy_probe(struct i2c_client *client, const struct i2c_device_id *id) {
    pr_info("dummy_device: Successful probe for device at address 0x%x\n", client->addr);
    return 0;
}

static void dummy_remove(struct i2c_client *client) {
    pr_info("dummy_device: Device removed from address 0x%x\n", client->addr);
}

static const struct i2c_device_id dummy_id[] = {
    { "dummy-device", 0 },
    { }
};
MODULE_DEVICE_TABLE(i2c, dummy_id);

static const struct of_device_id dummy_of_match[] = {
    { .compatible = "krinkin,dummy-device" },
    { }
};
MODULE_DEVICE_TABLE(of, dummy_of_match);

static struct i2c_driver dummy_driver = {
    .driver = {
        .name = "dummy_device_driver",
        .of_match_table = dummy_of_match,
    },
    .probe = dummy_probe,
    .remove = dummy_remove,
    .id_table = dummy_id,
};

module_i2c_driver(dummy_driver);
