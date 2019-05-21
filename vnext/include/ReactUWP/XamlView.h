// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#pragma once

#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.UI.Xaml.h>

namespace winrt {
  using namespace Windows::UI::Xaml;
  using namespace Windows::Foundation;
}

namespace react { namespace uwp {

typedef winrt::DependencyObject XamlView;

inline int64_t GetTag(XamlView view)
{
  return view.GetValue(winrt::FrameworkElement::TagProperty()).as<winrt::IPropertyValue>().GetInt64();
}

inline void SetTag(XamlView view, int64_t tag)
{
  view.SetValue(winrt::FrameworkElement::TagProperty(), winrt::PropertyValue::CreateInt64(tag));
}

inline void SetTag(XamlView view, winrt::IInspectable tag)
{
  SetTag(view, tag.as<winrt::IPropertyValue>().GetInt64());
}

} }
