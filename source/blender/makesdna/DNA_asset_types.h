/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

/** \file
 * \ingroup DNA
 */

#ifndef __DNA_ASSET_TYPES_H__
#define __DNA_ASSET_TYPES_H__

#include "DNA_ID.h"

typedef struct Asset {
  ID id;

  /** Thumbnail image of the data-block. Duplicate of the referenced ID preview. */
  struct PreviewImage *preview;
  /** Optional description of this asset for display in the UI. Dynamic length. */
  char *description;
  /** User defined tags for this asset. The asset manager uses these for filtering, but how they
   * function exactly (e.g. how they are registered to provide a list of searchable available tags)
   * is up to the asset-engine. */
  ListBase tags; /* CustomTag */

  /** The ID this asset was created for. */
  ID *referenced_id;
} Asset;

/**
 * \brief User defined tag.
 * Currently only used by assets, could be used more often at some point.
 * Maybe add a custom icon and color to these in future?
 */
typedef struct CustomTag {
  struct CustomTag *next, *prev;
  char name[64]; /* MAX_NAME */
} CustomTag;

/* TODO unused, keeping in case it's useful later. */
typedef struct AssetData {
  int dummy;
} AssetData;

#endif /* __DNA_ASSET_TYPES_H__ */
