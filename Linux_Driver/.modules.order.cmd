cmd_/home/pi/training/Linux_Driver/modules.order := {   echo /home/pi/training/Linux_Driver/mymodule.ko; :; } | awk '!x[$$0]++' - > /home/pi/training/Linux_Driver/modules.order
