#pragma once
#include "Figure.h"
#include "NumberConcept.h"

template <Number T>
class Six : public Figure<T> {
   template <Number U>
   friend std::ostream& operator<<(std::ostream& os, const Six<U>& figure);
   template <Number U>
   friend std::istream& operator>>(std::istream& is, Six<U>& figure);

  public:
   Six();
   Six(const std::shared_ptr<Point<T>> points);
   Six(const Six<T>& other);
   Six(Six<T>&& other);

   virtual ~Six() = default;

   virtual std::ostream& print(std::ostream& os) const override;
   virtual std::istream& read(std::istream& is) override;

   virtual operator double() const override;
   virtual Point<T> center() const override;

   Six<T>& operator=(const Six<T>& other);
   Six<T>& operator=(Six<T>&& other);
   bool operator==(Six<T>& other);

   virtual Figure<T>& operator=(const Figure<T>&& other) override;
   virtual Figure<T>& operator=(const Figure<T>& other) override;
   virtual bool operator==(const Figure<T>& other) override;

  private:
   virtual void fillPoints(const int pointsAmount, Point<T>* res,
                           const Point<T>* data) override;
};
template <Number T>
std::ostream& operator<<(std::ostream& os, const Six<T>& figure);
template <Number T>
std::istream& operator>>(std::istream& is, Six<T>& figure);