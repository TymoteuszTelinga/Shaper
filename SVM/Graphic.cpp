
#include "Graphic.hpp"

EllipseShape::EllipseShape(const sf::Vector2f& radius)
{
    m_radius = radius;
    update();
}

void EllipseShape::setRadius(const sf::Vector2f& radius)
{
    m_radius = radius;
    update();
}

const sf::Vector2f& EllipseShape::getRadius() const
{
     return m_radius;
}

std::size_t EllipseShape::getPointCount() const 
{
    return (std::size_t)30;
}

sf::Vector2f EllipseShape::getPoint(std::size_t index) const 
{
    static const float pi = 3.141592654f;

    float angle = index * 2 * pi / getPointCount() - pi / 2;
    float x = std::cos(angle) * m_radius.x;
    float y = std::sin(angle) * m_radius.y;

    return sf::Vector2f(m_radius.x + x, m_radius.y + y);
}

Graphic::Graphic()
{
    window.create(sf::VideoMode(400, 400), "SVM");
    window.setFramerateLimit(120);
    windowHeight = 400;
    t1 = std::chrono::high_resolution_clock::now();
}

Graphic::~Graphic()
{
    
}

void Graphic::ProcedEvents()
{
    sf::Event event;
    while(window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

bool Graphic::isOpen() const
{
    return window.isOpen();
}

void Graphic::Create(int width, int height)
{
    window.create(sf::VideoMode(width,height),"SVM");
    windowHeight = height;
}

void Graphic::Display()
{
    auto t2 = std::chrono::high_resolution_clock::now();
    float fps = 1.0 / std::chrono::duration_cast<std::chrono::nanoseconds>(t2-t1).count();
    t1 = t2;
    char c[6];
    sprintf(c, "%f", fps*1000000000);
    std::string str(c);
    window.setTitle(str);
    window.display();
}

void Graphic::Clear()
{
    window.clear();
}

void Graphic::DrawRect(int x, int y, int width, int height, int color)
{
    sf::RectangleShape shape({(float)width,(float)height});
    shape.setSize({(float)width,(float)height});
    shape.setOrigin(0,height);
    shape.setPosition(x,windowHeight - y);
    shape.setFillColor(sf::Color(color));
    window.draw(shape);
}

void Graphic::DrawEpise(int x, int y, int R1, int R2, int color)
{
    EllipseShape shape({(float)R1,(float)R2});
    shape.setOrigin(R1,R2);
    shape.setPosition(x,windowHeight-y);
    shape.setFillColor(sf::Color(color));
    window.draw(shape);
}

void Graphic::DrawLine(int x1, int y1, int x2, int y2, int color)
{
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(x1, windowHeight - y1);
    line[0].color = sf::Color(color);
    line[1].position = sf::Vector2f(x2, windowHeight - y2);
    line[1].color = sf::Color(color);
    window.draw(line,2,sf::Lines); 
}

void Graphic::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, int color)
{
    sf::ConvexShape convex;
    convex.setPointCount(3);
    convex.setPoint(0, sf::Vector2f(x1, windowHeight-y1));
    convex.setPoint(1, sf::Vector2f(x2, windowHeight-y2));
    convex.setPoint(2, sf::Vector2f(x3, windowHeight-y3));
    convex.setFillColor(sf::Color(color));
    window.draw(convex);
}
