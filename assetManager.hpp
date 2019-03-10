/*
 * Created by Martin Karlsson on 2019-03-10.
 */

#ifndef STUFFTHING_ASSETMANAGER_HPP
#define STUFFTHING_ASSETMANAGER_HPP

#include <map>
#include <SFML/Graphics.hpp>

namespace Chauwa
{
    class AssetManager
    {
    public:
        AssetManager()
        {}
        ~AssetManager()
        {}

        void loadTexture(std::string name, std::string fileName);
        sf::Texture &getTexture(std::string name);

        void loadFont(std::string name, std::string fileName);
        sf::Font &getFont(std::string name);

    private:
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Font> _fonts;
    };
}

#endif //STUFFTHING_ASSETMANAGER_HPP
