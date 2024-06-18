#pragma once
#include<iostream>
#include<string>

using namespace std;

class MusicTrack
{
private:
	string name;
public:
	MusicTrack(const string& name)
		:name(name) {}
	MusicTrack() = default;
	string GetName() { return name; };
	
};

