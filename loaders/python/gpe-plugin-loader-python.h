/*
 * gpe-plugin-loader-python.h
 * This file is part of libgpe
 *
 * Copyright (C) 2008 - Jesse van den Kieboom
 * Copyright (C) 2009 - Steve Frécinaux
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

#ifndef __GPE_PLUGIN_LOADER_PYTHON_H__
#define __GPE_PLUGIN_LOADER_PYTHON_H__

#include <libgpe/gpe-plugin-loader.h>

G_BEGIN_DECLS

#define GPE_TYPE_PLUGIN_LOADER_PYTHON			(gpe_plugin_loader_python_get_type ())
#define GPE_PLUGIN_LOADER_PYTHON(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), GPE_TYPE_PLUGIN_LOADER_PYTHON, GPEPluginLoaderPython))
#define GPE_PLUGIN_LOADER_PYTHON_CONST(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GPE_TYPE_PLUGIN_LOADER_PYTHON, GPEPluginLoaderPython const))
#define GPE_PLUGIN_LOADER_PYTHON_CLASS(klass)		(G_TYPE_CHECK_CLASS_CAST ((klass), GPE_TYPE_PLUGIN_LOADER_PYTHON, GPEPluginLoaderPythonClass))
#define GPE_IS_PLUGIN_LOADER_PYTHON(obj)		(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GPE_TYPE_PLUGIN_LOADER_PYTHON))
#define GPE_IS_PLUGIN_LOADER_PYTHON_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), GPE_TYPE_PLUGIN_LOADER_PYTHON))
#define GPE_PLUGIN_LOADER_PYTHON_GET_CLASS(obj)		(G_TYPE_INSTANCE_GET_CLASS ((obj), GPE_TYPE_PLUGIN_LOADER_PYTHON, GPEPluginLoaderPythonClass))

typedef struct _GPEPluginLoaderPython			GPEPluginLoaderPython;
typedef struct _GPEPluginLoaderPythonClass		GPEPluginLoaderPythonClass;
typedef struct _GPEPluginLoaderPythonPrivate		GPEPluginLoaderPythonPrivate;

struct _GPEPluginLoaderPython {
	GObject parent;

	GPEPluginLoaderPythonPrivate *priv;
};

struct _GPEPluginLoaderPythonClass {
	GObjectClass parent_class;
};

GType gpe_plugin_loader_python_get_type (void) G_GNUC_CONST;
GPEPluginLoaderPython *gpe_plugin_loader_python_new (void);

/* All the loaders must implement this function */
G_MODULE_EXPORT GType register_gpe_plugin_loader (GTypeModule * module);

G_END_DECLS

#endif /* __GPE_PLUGIN_LOADER_PYTHON_H__ */
