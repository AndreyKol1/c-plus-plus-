#include "Playlist.h"

int binarySearch(vector<string>& vec, const string& name)
{
    
    sort(vec.begin(), vec.end(), [](string& a, string& b) { return a < b; });
    int right = vec.size() - 1;
    int left = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (vec[mid] < name)
            left = mid + 1;
        else if (vec[mid] > name)
            right = mid - 1;
        else
            return mid;
    }
    return -1;
}

bool Playlist::ifInPlaylist(const string& name)
{
    int index = binarySearch(tracks, name);
    return index != -1 ? true : false;
}

void Playlist::removeTrack(const string& trackName)
{
    int index = binarySearch(tracks, trackName);
    

    if (index != -1)
        tracks.erase(tracks.begin() + index);
    else
        cout << "Track is not found" << endl;
}








