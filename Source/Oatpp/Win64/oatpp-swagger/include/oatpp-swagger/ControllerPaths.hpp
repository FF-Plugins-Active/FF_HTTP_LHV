/***************************************************************************
 *
 * Project         _____    __   ____   _      _
 *                (  _  )  /__\ (_  _)_| |_  _| |_
 *                 )(_)(  /(__)\  )( (_   _)(_   _)
 *                (_____)(__)(__)(__)  |_|    |_|
 *
 *
 * Copyright 2018-present, Leonid Stryzhevskyi, <lganzzzo@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ***************************************************************************/

#ifndef oatpp_swagger_ControllerPaths_hpp
#define oatpp_swagger_ControllerPaths_hpp

#include "oatpp/core/Types.hpp"

namespace oatpp { namespace swagger {

/**
 * Swagger Controller endpoints paths.
 */
struct ControllerPaths {

  /**
   * Path to generated API JSON.
   */
  oatpp::String apiJson = "api-docs/oas-3.0.0.json";

  /**
   * Path to swagger UI (index.html).
   */
  oatpp::String ui = "swagger/ui";

  /**
   * Path to other ui resources. MUST contain `/{filename}` at the end.
   */
  oatpp::String uiResources = "swagger/{filename}";

};

}}

#endif //oatpp_swagger_ControllerPaths_hpp
