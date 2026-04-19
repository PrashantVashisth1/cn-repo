# Experiment - 4(vlan with switch)
<img width="865" height="475" alt="image" src="https://github.com/user-attachments/assets/645050a9-0138-4807-b6f7-2b965225c130" />

## switch cli

```python

enable
configure terminal

vlan 10
name VLAN10
exit

vlan 20
name VLAN20
exit
```

```python

interface range fa0/1 - 2
switchport mode access
switchport access vlan 10
exit

interface range fa0/3 - 4
switchport mode access
switchport access vlan 20
exit
```

# Experiment - 5(inter vlan with router)
<img width="900" height="658" alt="image" src="https://github.com/user-attachments/assets/948b5f53-fa9d-45df-8f4b-64612db05f8a" />

## switch cli

```python
enable
configure terminal

vlan 10
exit
vlan 20
exit
```

```python
interface range fa0/1 - 2
switchport mode access
switchport access vlan 10
exit

interface range fa0/3 - 4
switchport mode access
switchport access vlan 20
exit
```

```python
interface fa0/5
switchport mode trunk
exit
```

## router configuration

```python
enable
configure terminal
```

```python
interface f0/0
no shutdown
exit
```

```python
interface f0/0.10
encapsulation dot1Q 10
ip address 192.168.1.254 255.255.255.0
exit

interface f0/0.20
encapsulation dot1Q 20
ip address 192.168.2.254 255.255.255.0
exit
```

### assign ip address

<img width="624" height="488" alt="image" src="https://github.com/user-attachments/assets/53c48439-1a67-4e04-9ef2-982aaefec97a" />

# experiment 7 (to design internetworking between two separate lans using router and switch)

<img width="1150" height="636" alt="image" src="https://github.com/user-attachments/assets/3e5b029c-be74-4644-a45c-2afebe11f990" />

## no configuration in switches

## just fill all ip like this of pc0

<img width="1061" height="1066" alt="image" src="https://github.com/user-attachments/assets/5fdf40eb-580c-4c2f-894e-cfd7461b1aff" />

## now router configuration in cli

```python
enable
configure terminal

interface fa0/0
ip address 192.168.1.254 255.255.255.0
no shutdown

interface fa0/1
ip address 192.168.2.254 255.255.255.0
no shutdown

exit
```

# experiment 8 (dhcp using server)

<img width="469" height="582" alt="image" src="https://github.com/user-attachments/assets/10e85bbe-d683-4c68-99b6-a3fd060d6252" />

## no code just some images for setting up server

<img width="1043" height="1059" alt="image" src="https://github.com/user-attachments/assets/f8b616bb-406d-4ea9-bbde-d31947b43103" />
<img width="1041" height="1061" alt="image" src="https://github.com/user-attachments/assets/2350dab0-40a8-4fe1-ae6b-2d42865f98b5" />
## !!!!!!!!!!!!!!!!REMEMBER TO SAVE THE SERVICE!!!!!!!!!!

# experiment 8 (dhcp using router)

<img width="633" height="628" alt="image" src="https://github.com/user-attachments/assets/8798f454-6dc1-42c0-9cd3-d1188d145c53" />

## router configuration

```python
enable
configure terminal

interface fa0/0
ip address 192.168.1.1 255.255.255.0
no shutdown
exit
```

```python
ip dhcp excluded-address 192.168.1.1 192.168.1.9
```

```python
ip dhcp pool LAN
network 192.168.1.0 255.255.255.0
default-router 192.168.1.1
dns-server 8.8.8.8
```

# experiment 6 (router configure)

<img width="547" height="316" alt="image" src="https://github.com/user-attachments/assets/2789a9c9-2211-462d-9496-38685defddc5" />

## follow all the steps carefully!!

<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/feff27ea-2f0d-4028-9787-03307ece77bf" />

<img width="960" height="1280" alt="image" src="https://github.com/user-attachments/assets/0926ac75-37f2-417c-96ba-a47495481f1d" />









