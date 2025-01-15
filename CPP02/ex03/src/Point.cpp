/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:19:50 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/21 18:19:53 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {
}

Point::Point(const float x_val, const float y_val) : x(x_val), y(y_val) {
}

Point::Point(const Point& other) : x(other.x), y(other.y) {
}

Point& Point::operator=(const Point& other) {
    // Since x and y are const, we can't modify them
    // This is a special case where we just return *this
    (void)other;
    return *this;
}

Point::~Point() {
}

Fixed Point::getX() const {
    return x;
}

Fixed Point::getY() const {
    return y;
}