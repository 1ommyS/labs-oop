#pragma once
#include "Validator.h"

template <class T>
class SixValidator : public Validator<T> {
  public:
   void validate(const Figure<T>& figure1) const override;
   virtual bool isAllowed(const Figure<T>& fugure) const override;
};