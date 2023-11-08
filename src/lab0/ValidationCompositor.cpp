#include "ValidationCompositor.h"
#include <memory>
#include <vector>
#include "PentagonValidation.cpp"
#include "PentagonValidation.h"
#include "RombValidation.cpp"
#include "RombValidation.h"
#include "SixValidation.cpp"
#include "SixValidation.h"

template <class T>
void ValidationCompositor<T>::validate(Figure<T> &figure) const {
   for (std::shared_ptr<VaLidationHandler<T>> validator : validations) {

      if (validator.get()->isAllowed(figure)) {
         validator.get()->validate(figure);
         return;
      }
   }
}

template <class T>
ValidationCompositor<T>::ValidationCompositor() {

   validations.push_back(std::shared_ptr<VaLidationHandler<T>>(
       dynamic_cast<VaLidationHandler<T> *>(new TrapValidationHandler<T>())));
   validations.push_back(std::shared_ptr<VaLidationHandler<T>>(
       dynamic_cast<VaLidationHandler<T> *>(new RombValidationHandler<T>())));
   validations.push_back(std::shared_ptr<VaLidationHandler<T>>(
       dynamic_cast<VaLidationHandler<T> *>(
           new PentagonValidationHandler<T>())));
}
