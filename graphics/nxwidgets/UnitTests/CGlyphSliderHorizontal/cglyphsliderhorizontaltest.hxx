/////////////////////////////////////////////////////////////////////////////
// apps/graphics/nxwidgets/UnitTests/CGlyphSliderHorizontal/cglyphsliderhorizontaltest.hxx
//
// SPDX-License-Identifier: Apache-2.0
//
// Licensed to the Apache Software Foundation (ASF) under one or more
// contributor license agreements.  See the NOTICE file distributed with
// this work for additional information regarding copyright ownership.  The
// ASF licenses this file to you under the Apache License, Version 2.0 (the
// "License"); you may not use this file except in compliance with the
// License.  You may obtain a copy of the License at
//
//   http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
// WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See the
// License for the specific language governing permissions and limitations
// under the License.
//
//////////////////////////////////////////////////////////////////////////////

#ifndef __APPS_GRAPHICS_NXWIDGETS_UNITTESTS_CGLYPHSLIDERHORIZONTAL_CGLYPHSLIDERHORIZONTALTEST_HXX
#define __APPS_GRAPHICS_NXWIDGETS_UNITTESTS_CGLYPHSLIDERHORIZONTAL_CGLYPHSLIDERHORIZONTALTEST_HXX

/////////////////////////////////////////////////////////////////////////////
// Included Files
/////////////////////////////////////////////////////////////////////////////

#include <nuttx/config.h>

#include <nuttx/init.h>
#include <cstdio>
#include <semaphore.h>
#include <debug.h>

#include <nuttx/nx/nx.h>

#include "graphics/nxwidgets/nxconfig.hxx"
#include "graphics/nxwidgets/cwidgetcontrol.hxx"
#include "graphics/nxwidgets/ccallback.hxx"
#include "graphics/nxwidgets/cbgwindow.hxx"
#include "graphics/nxwidgets/cnxserver.hxx"
#include "graphics/nxwidgets/cglyphsliderhorizontal.hxx"

/////////////////////////////////////////////////////////////////////////////
// Definitions
/////////////////////////////////////////////////////////////////////////////
// Configuration ////////////////////////////////////////////////////////////

#ifndef CONFIG_HAVE_CXX
#  error "CONFIG_HAVE_CXX must be defined"
#endif

#ifndef CONFIG_CGLYPHSLIDERHORIZONTALTEST_BGCOLOR
#  define CONFIG_CGLYPHSLIDERHORIZONTALTEST_BGCOLOR CONFIG_NXWIDGETS_DEFAULT_BACKGROUNDCOLOR
#endif

/////////////////////////////////////////////////////////////////////////////
// Public Classes
/////////////////////////////////////////////////////////////////////////////

using namespace NXWidgets;

class CGlyphSliderHorizontalTest : public CNxServer
{
private:
  CWidgetControl    *m_widgetControl;  // The controlling widget for the window
  CBgWindow         *m_bgWindow;       // Background window instance

public:
  // Constructor/destructors

  CGlyphSliderHorizontalTest(void);
  ~CGlyphSliderHorizontalTest(void);

  // Initializer/unitializer.  These methods encapsulate the basic steps for
  // starting and stopping the NX server

  bool connect(void);
  void disconnect(void);

  // Create a window.  This method provides the general operations for
  // creating a window that you can draw within.
  //
  // Those general operations are:
  // 1) Create a dumb CWigetControl instance
  // 2) Pass the dumb CWidgetControl instance to the window constructor
  //    that inherits from INxWindow.  This will "smarten" the CWidgetControl
  //    instance with some window knowlede
  // 3) Call the open() method on the window to display the window.
  // 4) After that, the fully smartened CWidgetControl instance can
  //    be used to generate additional widgets by passing it to the
  //    widget constructor

  bool createWindow(void);

  // Create a slider in the center of the window

  CGlyphSliderHorizontal *createSlider(void);

  // (Re-)draw the slider.

  void showSlider(CGlyphSliderHorizontal *slider);
};

/////////////////////////////////////////////////////////////////////////////
// Public Data
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
// Public Function Prototypes
/////////////////////////////////////////////////////////////////////////////

#endif // __APPS_GRAPHICS_NXWIDGETS_UNITTESTS_CGLYPHSLIDERHORIZONTAL_CGLYPHSLIDERHORIZONTALTEST_HXX
