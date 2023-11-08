#pragma once
#include "Validator.h"

template <class T> class PentagonValidator: public Validator<T>{
    public:
        void validate(const Figure<T>& figure1) const  override;
        bool isAllowed(const Figure<T>& fugure) const override;
};