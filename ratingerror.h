#ifndef RATINGERROR_H
#define RATINGERROR_H

#include<stdexcept>
#include<string>

class RatingError : public std::logic_error
{
private:
    std::string nameEmployee;
    unsigned int gradiMancanti;
public:
    RatingError(std::string, unsigned int);
    std::string Employee() const;
};

#endif // RATINGERROR_H
