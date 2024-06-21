sudo ip addr flush dev eth0
sudo ip addr add 10.5.5.1/24 dev eth0
sudo ip link set eth0 up
sudo ip addr show dev eth0
sudo dnsmasq -C /dev/null -kd -F 10.5.5.50,10.5.5.100 -i eth0 --bind-dynamic
