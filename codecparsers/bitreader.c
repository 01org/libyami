/* reamer
 *
 * Copyright (C) 2008 Sebastian Dröge <sebastian.droege@collabora.co.uk>.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin St, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define BIT_READER_DISABLE_INLINES
#include "bitreader.h"

#include <string.h>

/**
 * SECTION:bitreader
 * @short_description: Reads any number of bits from a memory buffer
 *
 * #BitReader provides a bit reader that can read any number of bits
 * from a memory buffer. It provides functions for reading any number of bits
 * into 8, 16, 32 and 64 bit variables.
 */

/**
 * bit_reader_new:
 * @data: (array length=size): Data from which the #BitReader
 *   should read
 * @size: Size of @data in bytes
 *
 * Create a new #BitReader instance, which will read from @data.
 *
 * Free-function: bit_reader_free
 *
 * Returns: (transfer full): a new #BitReader instance
 */
BitReader *
bit_reader_new (const uint8_t * data, uint32_t size)
{
  BitReader *ret = g_slice_new0 (BitReader);

  ret->data = data;
  ret->size = size;

  return ret;
}

/**
 * bit_reader_free:
 * @reader: (in) (transfer full): a #BitReader instance
 *
 * Frees a #BitReader instance, which was previously allocated by
 * bit_reader_new().
 */
void
bit_reader_free (BitReader * reader)
{
  g_return_if_fail (reader != NULL);

  g_slice_free (BitReader, reader);
}

/**
 * bit_reader_init:
 * @reader: a #BitReader instance
 * @data: (in) (array length=size): data from which the bit reader should read
 * @size: Size of @data in bytes
 *
 * Initializes a #BitReader instance to read from @data. This function
 * can be called on already initialized instances.
 */
void
bit_reader_init (BitReader * reader, const uint8_t * data, uint32_t size)
{
  g_return_if_fail (reader != NULL);

  reader->data = data;
  reader->size = size;
  reader->byte = reader->bit = 0;
}

/**
 * bit_reader_set_pos:
 * @reader: a #BitReader instance
 * @pos: The new position in bits
 *
 * Sets the new position of a #BitReader instance to @pos in bits.
 *
 * Returns: %TRUE if the position could be set successfully, %FALSE
 * otherwise.
 */
bool
bit_reader_set_pos (BitReader * reader, uint32_t pos)
{
  g_return_val_if_fail (reader != NULL, FALSE);

  if (pos > reader->size * 8)
    return FALSE;

  reader->byte = pos / 8;
  reader->bit = pos % 8;

  return TRUE;
}

/**
 * bit_reader_get_pos:
 * @reader: a #BitReader instance
 *
 * Returns the current position of a #BitReader instance in bits.
 *
 * Returns: The current position of @reader in bits.
 */
uint32_t
bit_reader_get_pos (const BitReader * reader)
{
  return _bit_reader_get_pos_inline (reader);
}

/**
 * bit_reader_get_remaining:
 * @reader: a #BitReader instance
 *
 * Returns the remaining number of bits of a #BitReader instance.
 *
 * Returns: The remaining number of bits of @reader instance.
 */
uint32_t
bit_reader_get_remaining (const BitReader * reader)
{
  return _bit_reader_get_remaining_inline (reader);
}

/**
 * bit_reader_get_size:
 * @reader: a #BitReader instance
 *
 * Returns the total number of bits of a #BitReader instance.
 *
 * Returns: The total number of bits of @reader instance.
 */
uint32_t
bit_reader_get_size (const BitReader * reader)
{
  return _bit_reader_get_size_inline (reader);
}

/**
 * bit_reader_skip:
 * @reader: a #BitReader instance
 * @nbits: the number of bits to skip
 *
 * Skips @nbits bits of the #BitReader instance.
 *
 * Returns: %TRUE if @nbits bits could be skipped, %FALSE otherwise.
 */
bool
bit_reader_skip (BitReader * reader, uint32_t nbits)
{
  return _bit_reader_skip_inline (reader, nbits);
}

/**
 * bit_reader_skip_to_byte:
 * @reader: a #BitReader instance
 *
 * Skips until the next byte.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */
bool
bit_reader_skip_to_byte (BitReader * reader)
{
  return _bit_reader_skip_to_byte_inline (reader);
}

/**
 * bit_reader_get_bits_uint8:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint8_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val and update the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

/**
 * bit_reader_get_bits_uint16:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint16_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val and update the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

/**
 * bit_reader_get_bits_uint32:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint32_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val and update the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

/**
 * bit_reader_get_bits_uint64:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint64_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val and update the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

/**
 * bit_reader_peek_bits_uint8:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint8_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val but keep the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

/**
 * bit_reader_peek_bits_uint16:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint16_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val but keep the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

/**
 * bit_reader_peek_bits_uint32:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint32_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val but keep the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

/**
 * bit_reader_peek_bits_uint64:
 * @reader: a #BitReader instance
 * @val: (out): Pointer to a #uint64_t to store the result
 * @nbits: number of bits to read
 *
 * Read @nbits bits into @val but keep the current position.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 */

#define BIT_READER_READ_BITS(bits) \
bool \
bit_reader_peek_bits_uint##bits (const BitReader *reader, uint##bits##_t *val, uint32_t nbits) \
{ \
  return _bit_reader_peek_bits_uint##bits##_inline (reader, val, nbits); \
} \
\
bool \
bit_reader_get_bits_uint##bits (BitReader *reader, uint##bits##_t *val, uint32_t nbits) \
{ \
  return _bit_reader_get_bits_uint##bits##_inline (reader, val, nbits); \
}

BIT_READER_READ_BITS (8);
BIT_READER_READ_BITS (16);
BIT_READER_READ_BITS (32);
BIT_READER_READ_BITS (64);
