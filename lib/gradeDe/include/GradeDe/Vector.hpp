/*
    Authors:
    >> Nathan TIROLF - { nathan.tirolf@epitech.eu }

    („• ֊ •„)❤  <  Have a good day !
    --U-----U------------------------
*/

#ifndef GRADE_DE_VECTOR_SFML_HPP_
    #define GRADE_DE_VECTOR_SFML_HPP_

    /*  ---- INCLUDES ---- */


    /*  ---- CLASS ---- */
namespace gd
{
    /**
     * \brief Class that represents a vector of two elements.
     *
     * \warning This class is a template class.
     */
    template <typename T>
    class Vector2
    {
        public:
            /**
             * \brief Default constructor.
             */
            Vector2();

            /**
             * \brief Constructor with parameters.
             *
             * This constructor creates a vector with the specified values.
             *
             * \param x The x component of the vector.
             * \param y The y component of the vector.
             *
             * \warning The vector class use template.
             */
            Vector2(T x, T y);

            /**
             * \brief Default destructor.
             */
            ~Vector2() = default;

            /**
             * \brief Overload of the + operator.
             */
            Vector2<T> operator+(const Vector2<T> &vector);

            /**
             * \brief Overload of the += operator.
             */
            Vector2<T> &operator+=(const Vector2<T> &vector);

            /**
             * \brief Overload of the - operator.
             */
            Vector2<T> operator-(const Vector2<T> &vector);

            /**
             * \brief Overload of the -= operator.
             */
            Vector2<T> &operator-=(const Vector2<T> &vector);

            /**
             * \brief Overload of the * operator.
             */
            Vector2<T> operator*(const Vector2<T> &vector);

            /**
             * \brief Overload of the *= operator.
             */
            Vector2<T> &operator*=(const Vector2<T> &vector);

            /**
             * \brief Overload of the / operator.
             */
            Vector2<T> operator/(const Vector2<T> &vector);

            /**
             * \brief Overload of the /= operator.
             */
            Vector2<T> &operator/=(const Vector2<T> &vector);


            /**
             * \brief The x value of the vector.
             */
            T x;

            /**
             * \brief The y value of the vector.
             */
            T y;
    };
}

#endif /* !GRADE_DE_VECTOR_SFML_HPP_ */
