# target: dependencies
# <tab> rule

# make (without arguments) executes first rule in file
# Ideally, one target for every object file and a target for final binary. 

final: UtPodDriver.o UtPod.o Song.o
	g++ -otest -std=c++0x UtPodDriver.o UtPod.o Song.o
driver: UtPodDriver.cpp UtPod.h Song.h
	g++ -c -std=c++0x UtPodDriver.cpp
UtPod.o: UtPod.cpp UtPod.h Song.h
	g++ -c -std=c++0x UtPod.cpp
Song.o: Song.cpp Song.h
	g++ -c -std=c++0x Song.cpp