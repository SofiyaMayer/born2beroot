*This project has been created as part of the 42 curriculum by someyer*

# Description
### Born2beroot
This project is about setting up Linux Server and it's management. I chose **Rocky Linux** distribution.

### Debian vs. Rocky

Choosing between Rocky Linux and Debian usually comes down to whether you want a system built for the **corporate Enterprise** (Rocky) or one built by the **Community** (Debian). Both are popular and stable, but they follow different philosophies.

Rocky has a different package manager **dnf** and **.rpm** format, while Debian has **apt** package manager and **.deb** format. 

Because these are distinct distributions, their default software can differ. For instance, Rocky Linux leverages *SELinux* and *firewalld* for security, whereas Debian typically relies on *AppArmor* and *UFW* (Uncomplicated Firewall). You'll also find variations in how configuration files are structured and located across the two systems.

### Brief Project Overview

According to project's guidelines, I needed to do following steps:

- Install Rocky Linux using VirtualBox
- Achieve similar partition table like in the project .pdf file
- Have hostname someyer42
- Configure SSH using 4242 port instead of standard 22
- Write my own bash monitoring script named *monitoring.sh*, which executes every 10 minutes.
- Have strong password policy (according to .pdf file)
- Configure sudo policy, having someyer42 account in following groups (someyer42, sudo)

I also chose to do bonuses for these projects, which includes:

- Configure lighttpd, mariadb, php, wordpress services
- Add service of my choice (I chose Jellyfin)


# Instructions

Run the Virtual Machine. Now we can ssh to this system from our terminal, e.g. :
```bash
ssh someyer42@localhost -p 4242
```

### Project's Checklist
Here's commands from project guidelines to check if everything's ready.

#### 1. Check partitions
```bash
lsblk
```
In result you should see this output:

![commands_checklist](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/lsblk.png?raw=true)

#### 2. Check OS release 
```bash
head -n 2 /etc/os-release
```
#### 3. Check SELinux status
```bash
sestatus
```
#### 4. Network and port configuration (TCP/UDP)
```bash
ss -tunlp
```

#### 5. Firewall Service Configuration
```bash
sudo firewall-cmd --list-service
```

#### 6. Firewall Port Configuration
```bash
sudo firewall-cmd --list-port
```
#### 7. Firewall State
```bash
sudo firewall-cmd --state
```

In result you should be having this output:

![Checklist](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/commands_checklist.png?raw=true)

### Sudo configuration and login check:

Let's check ```sudoers file``` using ```visudo``` command:

```bash
sudo visudo
```
Check for these lines:
* Attempts: Limited to 3 attempts.
```
Defaults passwd_tries=3
```

* Custom Message: An error message of my choice must appear on failure.
```
Defaults badpass_message="Oh no! Access denied!"
```
* Logging: All sudo actions (inputs and outputs) must be logged.
```
Defaults log_input, log_output
Defaults iodir="/var/log/sudo"
```
* TTY enabled 

```
Defaults requiretty
```
* Path must be secured
```
Defaults    secure_path = /sbin:/bin:/usr/sbin:/usr/bin
```

### Monitoring script

Monitoring script is located in ```/usr/local/bin``` and named ```monitoring.sh```.
Check content of this file.
You can run this file in ssh session and result will be seen in VM terminal.

```bash
cd /usr/local/bin
./monitoring.sh
```


![Monitoring script](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/monitoring_script.png?raw=true)

# Guide

I noticed that there is not many people who is doing Rocky Linux and not many resources and guides that is easy to navigate (I found only one guide in particular, that was kinda helpful - [link](https://github.com/AGolz/Born2beRoot?tab=readme-ov-file)). In result, I was motivated to write my own guide. I hope, that it will be helpful to someone.
## 1. Setting up Rocky using Oracle VirtualBox
First step is to create a virtual machine and install `Rocky linux` (minimal ISO can be downloaded [here](https://rockylinux.org/download)). According to the project guidelines, we need a version without GUI interface, so minimal ISO is more then enough.

![Creating a virtual machine](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/setup_vbox1.png?raw=true)

During the setup, you also need to configure hardware for the virtual machine. I gave **2 GB of RAM**, and **2 processors**, which is enough for my project (especially for minimal Rocky setup without GUI)

![Hardware](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/setup_vbox2.png?raw=true)

I also gave **31 GB** of space for my virtual Hard Disk.

<small>*I initially gave 30 GB, but after I noticed, that I'd need a little bit more space for my project needs, thats why I changed it to 31GB*</small>

![Hard Disk](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/setup_vbox3.png?raw=true)

Now click finish and your virtual machine is ready.

![Final VM](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/setup_vbox4.png?raw=true)

## 2. Rocky Installation

Now we can procees to Rocky installation.

Rocky has installer with GUI interface or just pure text version. 

*In my project I used both (after I noticed some troubles with text installer, I switched to GUI version to proceed with installation)*

![Choose installation](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/installation_1.png?raw=true)

At first step, when picture below appeared, I pressed `e` button end entered `inst.text` in the end of the line after `quiet` and pressed `Ctrl + x` to boot the installation.

![Choosing text installation](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/installation_2.png?raw=true)

When I entered, I pres./screenshots/structure_project.pngsed `alt + F2` to enter the shell, so I could manage my partitions according to project guidelines. For the reference, I needed to achieve this structure in the end:

![Partitions table](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/structure_project.png?raw=true)

When I entered the shell, I wanted to see how my hard disk is named, so I used `lsblk` command. My hard disk was named **sda** For managing partitions I used `fdisk`, there are other alternatives, like `parted`, but I already used fdisk before, so I chose to use it in this project.

For managing *sda* device, enter `fdisk /dev/sda` command. After that you can create/delete/edit partitions. I needed to created a new partition. For that case press `n` and `enter`

![Managing partitions via fdisk](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/guide_1.png?raw=true)

Now I needed to choose between primary / extended partition types. At first, I need to choose primary one, so press `p` and continue until you see the last sector. In the last sector I put 512 MiB (just enter `+512M`).

* *Note:* 
<small> During the installation, the system flagged 500 MiB as being below the recommended threshold for stability (that was the value from the project picture); I increased it to 512 MiB to ensure proper kernel updates and system boot reliability.</small>

Create the same way extended partition (press `e`) and continue with default size. After that, create it **one more time**, so you will end up with **sda5**, which will be encrypted further.

![extended partitions](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/guide_2.png?raw=true./screenshots/guide_2.png)

After you achieved similar structure, you can continue with disk encrypting. I encrypted it using LUKS format. Enter the following command:
```bash
cryptsetup luksFormat --type luks1 /dev/sda5
```

After that sda5 disk will be encrypted in LUKS format.

![LUKS formatting](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/luksformatting.png?raw=true./screenshots/luksformatting.png)

Now if you want to see the result, you need to open encrypted disk and enter your passphrase.

```bash
cryptsetup open /dev/sda5 sda5_crypt
```

Now you can enter ```lsblk``` command and see the result.

![Formatting result](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/crypteddisk_result.png?raw=true)

After that, create a physical volume inside our crypted container.

```bash
pvcreate /dev/mapper/sda5_crypt
```

Create LVMGroup volume group.

```bash
vgcreate LVMGroup /dev/mapper/sda5_crypt
```

Create root and swap logical volumes in LVMGroup.

```bash
lvcreate -L 10G LVMGroup -n root
```

```bash
lvcreate -L 2.3G LVMGroup -n swap
```


![root & swap created](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/root_swap.png?raw=true/screenshots/root_swap.png)


Now we need to format root in ext4 format, swap in swap format.

```bash
mkfs.ext4 /dev/LVMGroup/root
mkswap /dev/LVMGroup/swap
```

 Power off the machine and start again in GUI mode, where we can do the rest of installation. If you are failed to boot, just choose your ISO file.

* *Note:* 
<small> I tried to continue in text installation regime, but I had problems to configure mountpoints. I haven't found what was the issue. In GUI installator there is a straightforward way how to enter mountpoints and I didn't have any issues so I chose this variant. </small>

Enter GUI installation continue to ```Installation Destination```, click on available hard disk and choose ```Custom``` configuration option and continue.

![Entering GUI installation](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/gui_installation.png?raw=true./screenshots/gui_installation.png)
![Choosing Hard Disk](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/hd_choosing.png?raw=true./screenshots/hd_choosing.png)

Unlock your encrypted disk and enter passphrase.

![Enter passphrase GUI](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/enter_passphrase_gui.png?raw=true)

Now, under ```Unknown``` there's nothing we can do with ```sda1```. It's not a big deal, delete it, we will create it again later.

![Delete boot](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/del_unknown_boot.png?raw=true)

Click on ```root```, reformat it in ext4 and assign ``` '/' ``` mount point. You must reformat, otherwise you will catch an error.

![Assign root](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/root_reformat_gui.png?raw=true)

After that, reformat ```swap``` in swap format.

Click on plus button and enter ```/boot``` mountpoint, give it ```512M``` as we did it before. Reformat it in ext4 after it's done.

![Create boot](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/create_boot_gui.png?raw=true)


* *Note:*
If you'll try to continue, program could ask you to create ```biosboot``` mountpoint and give it ```1MiB``` of space. Do that for continuing installation. 

Now click ```Done``` and accept all of your changes.

Click on KDump and choose automatic option.

![Configue KDump](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/kdump.png?raw=true)
After that, you need to enable root account. Accessing root account via SSH should be disabled.

![Create rootuser](./screenshots/enable_rootuser.png)

Finally, you are done! Click on ```Begin installation``` and have a cookie!

![Ending installation](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/end_installation.png?raw=true)

## 3. Post installation

After we done, boot your system and login to your **root account**.


### Partitions
After installation, we need to add other logical volumes in our LVMGroup and mount them.

Let's create those logical volumes:

![other volumes](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/other_volumes.png?raw=true)

Now, when you execute ```lsblk``` command you will see this result:

![volumes not mounted](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/no_mounpoints_yet.png?raw=true)

These volumes need to be formatted and mounted. Let's do that with following commands:

```bash
mkfs.ext4 /dev/LVMGroup/home
mkfs.ext4 /dev/LVMGroup/var
mkfs.ext4 /dev/LVMGroup/srv
mkfs.ext4 /dev/LVMGroup/tmp
mkfs.ext4 /dev/LVMGroup/var-log
```

After formatting, let's mount devices:

```bash
mount /dev/LVMGroup/home /home
mount /dev/LVMGroup/var /var
mount /dev/LVMGroup/srv /srv
mount /dev/LVMGroup/tmp /tmp
mkdir /var/log
mount /dev/LVMGroup/var-log /var/log
```

After you write ```lsblk``` command, result will be:

![mounted devices](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/mounted_lsblk.png?raw=true)

In the next step, we want our system to do this mounting automatically. For that we can configure /etc/fstab file.

* *Note:*  <small>This file is critical, if you make a mistake, system could stop booting, so be cautious during the configuration.</small>

```bash
vi /etc/fstab
```

Write these configurations down below. Don't change anything what is already there:

```
/dev/mapper/LVMGroup-root /     ext4 defaults 0 0
/dev/mapper/LVMGroup-home /home ext4 defaults 0 0
/dev/mapper/LVMGroup-var /var   ext4 defaults 0 0
/dev/mapper/LVMGroup-srv /srv   ext4 defaults 0 0
/dev/mapper/LVMGroup-tmp /tmp   ext4 defaults 0 0
/dev/mapper/LVMGroup-var--log /var/log ext4 defaults 0 0
```

* *Note:* <small>I used device names here to keep things simple for this demo. In a real project, it’s better to use UUIDs (unique IDs). Device names can change if you plug in new hardware, which can break your setup. UUIDs never change. </small>

In result you will be having something like this:

![fstab config](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/fstab_config.png?raw=true)

Now we can check for errors using:

```bash
mount -a
```

If you **didn't catch any error** - that's good, we can reboot now and check if everything works. If you have errors, then check your /etc/fstab file again.

```bash
reboot
```

Let's check if our partitions are still correct:

![Check after reboot](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/check_after_reboot.png?raw=true)

Great! We have all partitions part done! Now we can continue with our project.

### Changing Hostname

Change hostname using following command

```bash
hostnamectl set-hostname [name]
```

Accordingly to project's guidelines, my hostname will be *someyer42*.
Edit ```/etc/hosts``` file, add a new line: ```127.0.1.1    someyer42``` below localhost lines.

```bash
vi /etc/hosts
```
![Hostname change](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/host_file.png?raw=true)

Now you can reboot and check new hostname using following command:
```bash
hostname
```

Check full name with this command:

```bash
hostname -f
```

Both should be showing your new hostname.

Now let's update your system.

```bash
dnf update
```

Install everything it shows and we are ready to continue.

* *Note:*
<small>```dnf update``` and ```dnf upgrade``` do the same thing in Rocky (they are aliases). It's not the case for Debian systems: ```apt update``` and ```apt upgrade``` are a bit different.</small>

## 4. Open-SSH configuration

Open-SSH is a way to connect to your server's shell remotely from another computer.

- Since we are switching the "entry door" from the default Port ```22``` to Port ```4242```, we have to do two extra things: tell the Firewall to let people through that new port, and tell SELinux to allow the SSH program to use it.

### Change ssh config file

Let's change standard port to ```4242``` in config file. Open this file: ```/etc/ssh/sshd_config```

Uncomment line with ```Port 22``` and change it to
```Port 4242```.

![Changing SSH config](https://github.com/SofiyaMayer/born2beroot/blob/master/screenshots/ssh_config.png?raw=true)

As you can notice, on SELinux system you also need to tell SELinux about this change.

### Telling SELinux about this change

SELinux (Security Enhanced Linux) is a security guard that labels every file and program to ensure they can only access what they are specifically allowed to, even if they have administrator power.

Run this command to add port 4242:
```bash
semanage port -a -t ssh_port_t -p tcp 4242
```
Without this command, SELinux will see the SSH service trying to use port 4242 and think, "Hey! SSH is only allowed to use port 22".

Now when it's done, let's add port 4242 to firewall.

### Adding port to our firewall


# Resources

- Rocky Linux Guides from their official website - [link](https://docs.rockylinux.org/guides/)

- Book - *How Linux Works* by Brian Ward

- Born2beroot guide, I found on internet - [link](https://github.com/AGolz/Born2beRoot)

- My peer *iskorepova* helped me a lot, when I couldn't resolve issues with bonuses.

- Google & Gemini for troubleshooting my problems.