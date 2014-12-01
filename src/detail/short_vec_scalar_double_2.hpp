/**
 * Copyright 2014 Andreas Schäfer
 *
 * Distributed under the Boost Software License, Version 1.0. (See accompanying
 * file LICENSE or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#ifndef FLAT_ARRAY_DETAIL_SHORT_VEC_SCALAR_DOUBLE_2_HPP
#define FLAT_ARRAY_DETAIL_SHORT_VEC_SCALAR_DOUBLE_2_HPP

#ifndef __SSE__

namespace LibFlatArray {

template<typename CARGO, int ARITY>
class short_vec;

#ifdef __ICC
// disabling this warning as implicit type conversion is exactly our goal here:
#pragma warning push
#pragma warning (disable: 2304)
#endif

template<>
Class short_vec<double, 2>
{
public:
    static const int ARITY = 2;

    inline
    short_vec(const double data = 0) :
        val1(data),
        val2(data)
    {}

    inline
    short_vec(const double *data) :
        val1(*(data +  0)),
        val2(*(data +  4))
    {}

    inline
    short_vec(const double& val1, const double& val2) :
        val1(val1),
        val2(val2)
    {}

    inline
    void operator-=(const short_vec<double, 2>& other)
    {
        val1 -= other.val1;
        val2 -= other.val2;
    }

    inline
    short_vec<double, 2> operator-(const short_vec<double, 2>& other) const
    {
        return short_vec<double, 2>(
            val1 - other.val1,
            val2 - other.val2);
    }

    inline
    void operator+=(const short_vec<double, 2>& other)
    {
        val1 += other.val1;
        val2 += other.val2;
    }

    inline
    short_vec<double, 2> operator+(const short_vec<double, 2>& other) const
    {
        return short_vec<double, 2>(
            val1 + other.val1,
            val2 + other.val2);
    }

    inline
    void operator*=(const short_vec<double, 2>& other)
    {
        val1 *= other.val1;
        val2 *= other.val2;
    }

    inline
    short_vec<double, 2> operator*(const short_vec<double, 2>& other) const
    {
        return short_vec<double, 2>(
            val1 * other.val1,
            val2 * other.val2);
    }

    inline
    void operator/=(const short_vec<double, 2>& other)
    {
        val1 /= other.val1;
        val1 /= other.val2;
    }

    inline
    short_vec<double, 2> operator/(const short_vec<double, 2>& other) const
    {
        return short_vec<double, 2>(
            val1 / other.val1,
            val2 / other.val2);
    }

    inline
    short_vec<double, 2> sqrt() const
    {
        return short_vec<double, 2>(
            sqrt(val1),
            sqrt(val2));
    }

    inline
    void store(double *data) const
    {
        *(data +  0) = val1;
        *(data +  4) = val2;
    }

private:
    double val1;
    double val2;
};

inline
void operator<<(double *data, const short_vec<double, 2>& vec)
{
    vec.store(data);
}

#ifdef __ICC
#pragma warning pop
#endif

short_vec<double, 2> sqrt(const short_vec<double, 2>& vec)
{
    return vec.sqrt();
}

}

#endif

#endif