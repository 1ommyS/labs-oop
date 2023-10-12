//
// Created by Ivan on 12.10.2023.
//

#include "validators/FigureValidator.h"

void FigureValidator::Validate(BaseFigure figure) {
    for (int i = 0; i < validators.size(); i++) {
        validators[i].Validate(figure);
    }
}
