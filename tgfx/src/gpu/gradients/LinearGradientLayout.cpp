/////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Tencent is pleased to support the open source community by making libpag available.
//
//  Copyright (C) 2021 THL A29 Limited, a Tencent company. All rights reserved.
//
//  Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file
//  except in compliance with the License. You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
//  unless required by applicable law or agreed to in writing, software distributed under the
//  license is distributed on an "as is" basis, without warranties or conditions of any kind,
//  either express or implied. see the license for the specific language governing permissions
//  and limitations under the license.
//
/////////////////////////////////////////////////////////////////////////////////////////////////

#include "LinearGradientLayout.h"
#include "opengl/GLLinearGradientLayout.h"

namespace tgfx {
std::unique_ptr<LinearGradientLayout> LinearGradientLayout::Make(Matrix matrix) {
  return std::unique_ptr<LinearGradientLayout>(new LinearGradientLayout(matrix));
}

LinearGradientLayout::LinearGradientLayout(Matrix matrix)
    : FragmentProcessor(ClassID()), coordTransform(matrix) {
  addCoordTransform(&coordTransform);
}

bool LinearGradientLayout::onIsEqual(const FragmentProcessor& processor) const {
  return coordTransform.matrix ==
         static_cast<const LinearGradientLayout&>(processor).coordTransform.matrix;
}

std::unique_ptr<GLFragmentProcessor> LinearGradientLayout::onCreateGLInstance() const {
  return std::make_unique<GLLinearGradientLayout>();
}
}  // namespace tgfx
