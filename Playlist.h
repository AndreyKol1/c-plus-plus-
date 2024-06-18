#pragma once
#include "MusicTrack.h"
#include <vector>
#include <algorithm>
using namespace std;

class Playlist
{
private:
	string name;
	vector<string> tracks;
public:
	Playlist(string name)
		:name(name) {}
	void addTrack(const string& name) { tracks.push_back(name);};
	bool ifInPlaylist (const string& name);
	string GetPlaylistName() { return name; };
	void removeTrack(const string& trackName);
	vector<string> GetTracks() { return tracks; };
	int GetSizeOfPlaylist() { return tracks.size(); };
};

