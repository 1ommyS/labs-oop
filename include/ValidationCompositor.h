#pragma once
#include <vector>
#include "Figure.h"
#include "PentagonValidator.h"
#include "RombValidator.h"
#include "SixValidator.h"
#include "Validator.h"

template <class T>
class ValidationCompositor {
  private:
   std::vector<std::shared_ptr<Validator<T>>> validations;

  public:
   ValidationCompositor();
   virtual ~ValidationCompositor() = default;
   void validate(Figure<T>& figure) const;
};