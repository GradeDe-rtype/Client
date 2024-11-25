/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_TEXTURE_SFML_HPP_
    #define GRADE_DE_TEXTURE_SFML_HPP_

    /*  ---- INCLUDES ---- */
    #include "GradeDe/Includes.hpp"
    #include "GradeDe/Error.hpp"
    #include "GradeDe/Vector.hpp"

    /*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents a texture.
     */
    class Texture
    {
        public:
            /**
             * \brief Default constructor.
             */
            Texture() = default;

            /**
             * \brief Default destructor.
             */
            ~Texture() = default;


            /**
             * \brief Load the texture from a file.
             *
             * \param path The path of the file.
             */
            void loadFromFile(const std::string &path);


            /**
             * \brief Get the texture.
             *
             * \return The texture as a void pointer.
             */
            void *getTexture();

            /**
             * \brief Get the size of the texture.
             *
             * \return The size of the texture as a vector of two integers.
             */
            gd::Vector2<int> getSize() const;

        private:
            sf::Texture _texture;
    };
}

#endif /* !GRADE_DE_TEXTURE_SFML_HPP_ */
