#include "loginvalidator.h"


LoginValidator::LoginValidator() : TFormValidator()
{
    setRule("email", Tf::Required, true, "Email is required");
    setRule("email", Tf::EmailAddress, true, "Email has not the correct format");
    setRule("password", Tf::Required, true, "Password is required");
    setRule("password", Tf::MinLength, 6, "Password has not the correct format");
}
