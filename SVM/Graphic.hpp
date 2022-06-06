#ifndef __GRAPHIC_H__
#define __GRAPHIC_H__

#include <SFML/Graphics.hpp>
#include <math.h>
#include <chrono>

class EllipseShape : public sf::Shape
{
private :
    sf::Vector2f m_radius;

public :
    explicit EllipseShape(const sf::Vector2f& radius = sf::Vector2f(0,0));

    void setRadius(const sf::Vector2f& radius);
    const sf::Vector2f& getRadius() const;
    virtual std::size_t getPointCount() const override;
    virtual sf::Vector2f getPoint(std::size_t index) const override;
};

class Graphic
{
private:
    sf::RenderWindow window;
    size_t windowHeight;

    std::chrono::time_point<std::chrono::high_resolution_clock> t1;

public:
    Graphic();
    ~Graphic();

    void ProcedEvents();
    bool isOpen() const;

    void Create(int width, int height);
    void Display();
    void Clear();
    void DrawRect(int x, int y, int width, int height, int color);
    void DrawEpise(int x, int y, int R1, int R2, int color);
    void DrawLine(int x1, int y1, int x2, int y2, int color);
    void DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color);
};

#endif // __GRAPHIC_H__