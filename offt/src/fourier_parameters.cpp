
//          Copyright Christian Volmer 2022.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          https://www.boost.org/LICENSE_1_0.txt)

#include <offt/fourier_parameters.h>

namespace offt {

FourierParameters const FourierParameters::Default  = { 1, 1 };
FourierParameters const FourierParameters::WolframLanguage = { 0, 1 };
FourierParameters const FourierParameters::Mathematica = FourierParameters::WolframLanguage;

}
