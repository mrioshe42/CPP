/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrios-he <mrios-he@student.42luxembourg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:20:39 by mrios-he          #+#    #+#             */
/*   Updated: 2024/11/21 18:36:43 by mrios-he         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool stringToFloat(const std::string& str, float& result)
{
    std::istringstream iss(str);
    return (iss >> result) && (iss.eof());
}

int main(int argc, char **argv)
{
    if (argc != 9)
    {
        std::cout << "Usage: " << argv[0] << " <triangle_x1> <triangle_y1> <triangle_x2> <triangle_y2> <triangle_x3> <triangle_y3> <point_x> <point_y>" << std::endl;
        return (1);
    }
    float x1, y1, x2, y2, x3, y3, px, py;
    try {
        if (!stringToFloat(argv[1], x1) || !stringToFloat(argv[2], y1) ||
            !stringToFloat(argv[3], x2) || !stringToFloat(argv[4], y2) ||
            !stringToFloat(argv[5], x3) || !stringToFloat(argv[6], y3) ||
            !stringToFloat(argv[7], px) || !stringToFloat(argv[8], py)) {
            throw std::invalid_argument("Invalid input format");
        }
    }
    catch (const std::exception& e)
    {
        std::cout << "Error: " << e.what() << std::endl;
        std::cout << "All arguments must be valid numbers" << std::endl;
        return (1);
    }
    Point a(x1, y1);
    Point b(x2, y2);
    Point c(x3, y3);
    Point point(px, py);
    std::cout << "Triangle vertices:" << std::endl;
    std::cout << "A(" << x1 << ", " << y1 << ")" << std::endl;
    std::cout << "B(" << x2 << ", " << y2 << ")" << std::endl;
    std::cout << "C(" << x3 << ", " << y3 << ")" << std::endl;
    std::cout << "Point to check: (" << px << ", " << py << ")" << std::endl;
    bool isInside = bsp(a, b, c, point);
    std::cout << "Result: Point is " << (isInside ? "inside" : "outside") << " the triangle" << std::endl;
    return 0;
}