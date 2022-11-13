#include "house.h"

// Determines if the house should hit or not
// Hit if total under
bool house::isHitting() const
{
    bool isHitting;

    if (getTotal() <= 16)
    {
        isHitting = true;
    }
    else
    {
        isHitting = false;
    }
    return isHitting;
}
