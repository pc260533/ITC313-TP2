#include "exceptionserialization.h"

ExceptionSerialization::ExceptionSerialization() {

}

ExceptionSerialization::~ExceptionSerialization() {

}

const char *ExceptionSerialization::what() const noexcept {
    return "Erreur de serialisation survenue.";
}
