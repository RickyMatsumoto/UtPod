/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    int memorySize = 500;
    UtPod t(memorySize);
    cout << "\n" << "Memory size is: \nMemory Size = " << memorySize << endl << endl;

    cout << "adding Closed on Sunday by Kanye West, size 5" << endl;
    Song s1("Kanye West", "Closed on Sunday", 5);
    int result = t.addSong(s1);
    cout << "result = " << result << "\n" << endl;

    cout << "adding Thotiana by Blueface, size 69" << endl;
    Song s2("Blueface", "Thotiana", 69);
    result = t.addSong(s2);
    cout << "result = " << result << "\n" << endl;

    cout << "adding N*ggas in Paris by Kanye West, size 4" << endl;
    Song s3("Kanye West", "N*ggas in Paris", 4);
    result = t.addSong(s3);
    cout << "result = " << result << "\n" << endl;

    cout << "adding Thotiana by Redface, size 7" << endl;
    Song s4("Redface", "Thotiana", 7);
    result = t.addSong(s4);
    cout << "result = " << result << "\n" << endl;

    cout << "adding Closed on Sunday by Kanye West, size 4" << endl;
    Song s5("Kanye West", "Closed on Sunday", 4);
    result = t.addSong(s5);
    cout << "add result = " << result << "\n" << endl;

    cout << "adding This Song is Too Big by Tatsushi Matsumoto, size 450" << endl;
    Song s6("This Song is Too Big", "Tatsushi Matsumoto", 450);
    result = t.addSong(s6);
    cout << "add result = " << result << "\n" << endl;

    cout << "Song list" << endl;
    t.showSongList();
    t.sortSongList();
    cout << "\n" << "Song list in order" << endl;
    t.showSongList();
    t.shuffle();
    cout << "\n" << "Song list shuffled" << endl;
    t.showSongList();

    cout << "\n" << "Deleting Thotiana by Blueface, size 69" << endl;
    result = t.removeSong(s2);
    cout << "delete result = " << result << "\n" << endl;

    cout << "Deleting N*ggas in Paris by Kanye West, size 4" << endl;
    result = t.removeSong(s3);
    cout << "delete result = " << result << "\n" << endl;

    cout << "These are the remaining songs" << endl;
    t.showSongList();

    cout << "\n" << "Memory size was: \nMemory Size = " << memorySize
    << "\nThis is the remaining memory: \nmemory = " << t.getRemainingMemory() << endl;

    cout << "\n" << "Deleting remaining songs" << endl;
    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl << endl;

    cout << "These are the remaining songs" << endl;
    t.showSongList();

}