#!/bin/bash
ssh-keygen

# add new ssh key to authorized keys
cat ~/.ssh/id_rsa.pub >> ~/.ssh/authorized_keys
_trust_host() { 
    ssh -o StrictHostKeyChecking=no -o ConnectTimeout=2 "$1" exit
}

# trust all eos machines
for i in {1..32}; do _trust_host "eos$(printf '%02d' $i)"; done

# trust all arch machines
for i in {1..10}; do _trust_host "arch$(printf '%02d' $i)"; done

# trust all datacomm machines
for i in {1..24}; do _trust_host "dc$(printf '%02d' $i)"; done

# automatic login
ssh eos08

