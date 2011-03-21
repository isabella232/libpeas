/*
 * extension-c.c
 * This file is part of libpeas
 *
 * Copyright (C) 2010 - Garrett Regier
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU Library General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "libpeas/peas-extension-base.h"
#include "loaders/c/peas-extension-c.h"

#include "testing/testing-extension.h"
#include "introspection/introspection-callable.h"
#include "introspection/introspection-properties.h"

static void
test_extension_c_instance_refcount (PeasEngine *engine)
{
  PeasPluginInfo *info;
  PeasExtension *extension;
  GObject *instance;

  info = peas_engine_get_plugin_info (engine, "extension-c");

  g_assert (peas_engine_load_plugin (engine, info));

  extension = peas_engine_create_extension (engine, info,
                                            INTROSPECTION_TYPE_CALLABLE,
                                            NULL);

  g_assert (PEAS_IS_EXTENSION (extension));

  instance = ((PeasExtensionC *) extension)->instance;

  /* The refcount of the returned object should be 1:
   *  - one ref for the PeasExtension
   */
  g_assert_cmpint (instance->ref_count, ==, 1);

  g_object_unref (extension);
}

static void
test_extension_c_plugin_info (PeasEngine *engine)
{
  PeasPluginInfo *info;
  PeasExtension *extension;
  PeasExtensionBase *instance;

  info = peas_engine_get_plugin_info (engine, "extension-c");

  g_assert (peas_engine_load_plugin (engine, info));

  extension = peas_engine_create_extension (engine, info,
                                            INTROSPECTION_TYPE_PROPERTIES,
                                            NULL);

  g_assert (PEAS_IS_EXTENSION (extension));

  instance = (PeasExtensionBase *) ((PeasExtensionC *) extension)->instance;

  g_assert (PEAS_IS_EXTENSION_BASE (instance));
  g_assert (peas_extension_base_get_plugin_info (instance) == info);

  g_object_unref (extension);
}

int
main (int   argc,
      char *argv[])
{
  g_test_init (&argc, &argv, NULL);
  g_type_init ();

  EXTENSION_TESTS (c);

  EXTENSION_TEST (c, "instance-refcount", instance_refcount);
  EXTENSION_TEST (c, "plugin-info", plugin_info);

  return testing_run_tests ();
}
