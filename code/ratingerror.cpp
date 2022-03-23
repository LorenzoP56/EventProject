#include "ratingerror.h"

RatingError::RatingError(std::string s, unsigned int i):
    std::logic_error("esperienza dell' impiegato " + s
                     +" non sufficientemente alta per la gestione di questo evento"), nameEmployee(s), gradiMancanti(i) {}

std::string RatingError::Employee() const
{
    std::string italiano = gradiMancanti == 1 ? " grado mancante " : " gradi mancanti ";
    return "l'impiegato " + nameEmployee + " deve essere sostituito ha " + std::to_string(gradiMancanti) + italiano + "per poter gestire al meglio l'evento";
}
