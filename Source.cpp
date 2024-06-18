#include "mainFunc.h"
#include <stack>

int main()
{
    srand(time(NULL));
    
    Playlist p1("Test");
    bool isPlaying = false;
    bool isPaused = false;
    float volume = 20;
    vector<string> mus;
    stack<string> playedTracks;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Music Library");

    sf::RectangleShape back;
    back.setSize(sf::Vector2f(800, 600));
    sf::Texture bg, playTEXTURE, pauseTEXTURE, volumeUp, volumeDown, skipNext, goBack, addToPl, removeFromPl, showPlayist;
    playTEXTURE.loadFromFile("img/play-button.png");
    pauseTEXTURE.loadFromFile("img/pause-button.png");
    volumeUp.loadFromFile("img/volume-up.png");
    volumeDown.loadFromFile("img/volume-down.png");
    skipNext.loadFromFile("img/next.png");
    goBack.loadFromFile("img/back.png");
    addToPl.loadFromFile("img/add1.png");
    removeFromPl.loadFromFile("img/remove.png");
    showPlayist.loadFromFile("img/button_show.png");
    bg.loadFromFile("img/back.jpg");
    back.setTexture(&bg);

    sf::Sprite playBTN(playTEXTURE), pauseBTN(pauseTEXTURE), volumeUpBTN(volumeUp), volumeDownBTN(volumeDown);
    sf::Sprite skipNextBTN(skipNext), goBackBTN(goBack), addToPlBTN(addToPl), removeFromPlBTN(removeFromPl), showPlaylistBTN(showPlayist);
    

    playBTN.setPosition({ 350,480 });
    volumeUpBTN.setPosition({ 700,490 });
    volumeDownBTN.setPosition({ 700,530 });
    skipNextBTN.setPosition({ 500, 500 });
    goBackBTN.setPosition({ 235, 500 });
    addToPlBTN.setPosition({ 185,42 });
    removeFromPlBTN.setPosition({ 230, 42 });
    showPlaylistBTN.setPosition({ 635, 38 });

    sf::Font arial;
    if (!arial.loadFromFile("fonts/ARIAL.ttf"))
        return 1;

    MusicSearchBox textbox(15, sf::Color::White, true);
    textbox.setFont(arial);
    textbox.setPosition({ 0,50 });
    textbox.setLimit(true, 15);

    
    Button btnPLAY(50, sf::Color::Black);
    btnPLAY.SetPosition({ 350,480 });
   
    VolumeUpBTN btnVolUP( 18, sf::Color::Black);
    btnVolUP.SetPosition({ 700, 490 });
    
    VolumeDownBTN btnVolDown( 18, sf::Color::Black);
    btnVolDown.SetPosition({ 700, 530 });

    NextSong skipBTN({ 55,55 }, sf::Color::Black);
    skipBTN.SetPosition({ 503, 503 });

    PreviousSong backBTN({ 55,55 }, sf::Color::Black);
    backBTN.SetPosition({ 237,502 });

    AddToPlaylist addBTN({29,29}, sf::Color::Black);
    addBTN.SetPosition({ 190,46 });

    RemoveBTN removeBTN({ 29,29 }, sf::Color::Black);
    removeBTN.SetPosition({ 231,43 });

    ShowPlaylist showBTN({ 155,43 }, sf::Color::Black);
    showBTN.SetPosition({ 635,38 });

    
    
    std::string myStr;
    sf::Music music;

    
    
    while (window.isOpen())
    {
        sf::Event evnt;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
        {
            textbox.setSelected(true);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            textbox.setSelected(false);
        }
        while (window.pollEvent(evnt))
        {
            
            switch (evnt.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                cout << "New width: " << evnt.size.width << "\tNew height: " << evnt.size.height << endl;
                break;
            case sf::Event::MouseMoved:
                if (btnPLAY.isMouseOver(window))
                {
                    changeHover(btnPLAY, sf::Color::White);
                }
                else
                {
                    changeHover(btnPLAY, sf::Color::Black);
                }
                if (btnVolUP.isMouseOver(window))
                {
                    changeHover(btnVolUP, sf::Color::White);
                }  
                else
                {
                    changeHover(btnVolUP, sf::Color::Black);
                }

                if (btnVolDown.isMouseOver(window))
                {
                    changeHover(btnVolDown, sf::Color::White);
                } 
                else
                {
                    changeHover(btnVolDown, sf::Color::Black);
                }

                if (skipBTN.isMouseOver(window))
                {
                    changeHover(skipBTN, sf::Color::White);
                    
                }
                else
                {
                    changeHover(skipBTN, sf::Color::Black);
                }

                if (backBTN.isMouseOver(window))
                {
                    changeHover(backBTN, sf::Color::White);
                }
                else
                {
                    changeHover(backBTN, sf::Color::Black);
                }

                if (addBTN.isMouseOver(window))
                {
                    changeHover(addBTN, sf::Color::White);
                }
                else
                {
                    changeHover(addBTN, sf::Color::Black);
                }

                if (removeBTN.isMouseOver(window))
                {
                    changeHover(removeBTN, sf::Color::White);
                }
                else
                {
                    changeHover(removeBTN, sf::Color::Black);
                }
                break;
            case sf::Event::MouseButtonPressed:
                if (btnPLAY.isMouseOver(window))
                {
                    BTNPlay(music, playTEXTURE, pauseTEXTURE, myStr, isPlaying, isPaused);
                }
                else if (btnVolUP.isMouseOver(window))
                {
                    addVolume(music, volume);
                }
                else if (btnVolDown.isMouseOver(window))
                {
                    reduceVolume(music, volume);
                }
                else if (addBTN.isMouseOver(window))
                
                {
                    addToPlaylist(p1,music, myStr, playTEXTURE, pauseTEXTURE, isPlaying);
                    
                }
                else if (skipBTN.isMouseOver(window))
                {
                    skipSong(mus, p1, playedTracks, music);
                }
                else if (backBTN.isMouseOver(window))
                {
                    playPrevious(p1, mus, playedTracks, music);
                }
                else if (removeBTN.isMouseOver(window))
                {
                    removeSong(p1, myStr);
                }
                else if (showBTN.isMouseOver(window))
                {
                    displayPlaylist(p1, mus);
                }
                break;
            case sf::Event::TextEntered:
                myStr.clear();
                textbox.typedOn(evnt);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
                    myStr += textbox.getText();
            }
        }

        window.clear();
        window.draw(back);
        btnPLAY.drawTo(window);
        btnVolUP.drawTo(window);
        btnVolDown.drawTo(window);
        skipBTN.drawTo(window);
        backBTN.drawTo(window);;
        addBTN.drawTo(window);
        removeBTN.drawTo(window);
        textbox.drawTo(window);
        showBTN.drawTo(window);
        
        window.draw(removeFromPlBTN);
        window.draw(playBTN);
        window.draw(volumeUpBTN);
        window.draw(volumeDownBTN);
        window.draw(skipNextBTN);
        window.draw(goBackBTN);
        window.draw(addToPlBTN);
        window.draw(showPlaylistBTN);
        window.display();
    }
    return 0;
}
