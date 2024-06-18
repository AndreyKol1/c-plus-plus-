#include "mainFunc.h"





void BTNPlay( sf::Music& music, sf::Texture& playTEXTURE, sf::Texture& pauseTEXTURE, const string& myStr, bool& isPlaying, bool& isPaused)
{
    
    try {
        if (isPlaying)
        {
            if (isPaused)
            {
                music.play();
                playTEXTURE.swap(pauseTEXTURE);
            }
            else
            {
                pauseTEXTURE.swap(playTEXTURE);
                music.pause();
            }
            isPaused = !isPaused;
        }
        else
        {
            if (myStr.empty() || !music.openFromFile("audio/" + myStr + ".wav"))
                throw std::runtime_error("Invalid music file or no file entered.");
            music.play();
            playTEXTURE.swap(pauseTEXTURE);
            isPlaying = true;
            isPaused = false;
        }
    }
    catch (std::exception& ex) {
        std::cerr << "Button pressed with no music entered!" << std::endl;
    }
}

void addVolume(sf::Music& music, float& volume)
{
    volume += 10;
    if (volume >= 100)
        volume = 100;
    music.setVolume(volume);
}

void reduceVolume(sf::Music& music, float& volume)
{
    volume -= 10;
    if (volume <= 0)
        volume = 0;
    music.setVolume(volume);
}

void addToPlaylist(Playlist& p1, sf::Music& music, string& myStr, sf::Texture& playTEXTURE, sf::Texture& pauseTEXTURE, bool& isPlaying)
{
    try
    {
        if (myStr.empty() || !music.openFromFile("audio/" + myStr + ".wav"))
        {
            stopMus(isPlaying, playTEXTURE, pauseTEXTURE, music);
            throw std::runtime_error("Invalid music file or no file entered.");
            
        }
            
        else
        {
            if (p1.ifInPlaylist(myStr))
            {
                cout << "Track is already in playlist" << endl;;
                myStr.clear();
                cout << "Enter name of the track again!" << endl;
            }
            else
            {
                p1.addTrack(myStr);
            }
                
            cout << "Tracks in playlist: " << endl;
            vector<string>tracksIn = p1.GetTracks();
            for (size_t i = 0; i < tracksIn.size(); i++)
            {
                cout << i + 1 << "." << tracksIn[i] << endl;
            }
        }
        stopMus(isPlaying, playTEXTURE, pauseTEXTURE, music);
    
    }
    catch (std::exception& ex)
    {
        std::cerr << "Button pressed with no music entered!" << std::endl;
    }
}

void skipSong(vector<string>& mus, Playlist& p1, stack<string>& playedTracks, sf::Music& music)
{
    mus = p1.GetTracks();
    if (p1.GetSizeOfPlaylist() == 0)
        cout << "Nothing to skip, playlist is empty!" << endl;
    else
    {
        string track = mus[rand() % p1.GetSizeOfPlaylist()];
        music.openFromFile("audio/" + track + ".wav");
        playedTracks.push(track);
        music.play();
    }
}

void playPrevious(Playlist& p1, vector<string>& mus, stack<string>& playedTracks, sf::Music& music)
{
    mus = p1.GetTracks();
    if (playedTracks.size() == 0)
    {
        cout << "Playlist is empty!" << endl;

    }
    else if (playedTracks.size() < 2)
    {
        music.openFromFile("audio/" + mus[p1.GetSizeOfPlaylist() - 1] + ".wav");
        music.play();
    }
    else
    {
        playedTracks.pop();
        music.openFromFile("audio/" + playedTracks.top() + ".wav");
        music.play();
    }
}

void removeSong(Playlist& p1, const string& myStr)
{
    if (myStr.empty() || p1.GetSizeOfPlaylist() == 0)
    {
        cout << "This could not be done!" << endl;
    }
    else
    {
        p1.removeTrack(myStr);
    }
}

void displayPlaylist(Playlist& p1, vector<string>& mus)
{
    if (p1.GetSizeOfPlaylist() == 0)
        cout << p1.GetPlaylistName() << " is empty!" << endl;
    else
    {
        cout << "Tracks in " << p1.GetPlaylistName() << ": " << endl;
        mus = p1.GetTracks();
        for (size_t i = 0; i < p1.GetSizeOfPlaylist(); i++)
        {
            cout << i + 1 << "." << mus[i] << endl;
        }
    }
}

void stopMus(bool& isPlaying, sf::Texture& playTEXTURE, sf::Texture& pauseTEXTURE, sf::Music& music)
{
    if (isPlaying)
    {
        playTEXTURE.swap(pauseTEXTURE);
        music.stop();
        isPlaying = false;
    }
}
