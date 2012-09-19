import subprocess

argv = ['/bin/sh']

p = subprocess.Popen(argv, executable = './vortex6.bin')        
p.wait()