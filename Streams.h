/*	File:		Streams.h	Contains:	Utility routines to stream data into a block of memory	Written by: Chris White		Copyright:	Copyright � 1995-1999 by Apple Computer, Inc., All Rights Reserved.				You may incorporate this Apple sample source code into your program(s) without				restriction. This Apple sample source code has been provided "AS IS" and the				responsibility for its operation is yours. You are not permitted to redistribute				this Apple sample source code as "Apple sample source code" after having made				changes. If you're going to re-distribute the source, we require that you make				it clear in the source that the code was descended from Apple sample source				code, but that you've made changes.	Change History (most recent first):				8/5/1999	Karl Groethe	Updated for Metrowerks Codewarror Pro 2.1				*/#ifndef __STREAMS__#define __STREAMS__#ifndef __TYPES__	#include <Types.h>#endif#ifndef __MEMORY__	#include <Memory.h>#endiftypedef struct StreamHeader{	Size	blockSize;	Size	currentSize;	Size	cursor;	Size	maxCursor;	} tStreamHeader, *tStreamHeaderPtr;typedef Ptr		tStreamRef;typedef UInt32	tStreamCursor;enum{	kInvalidStreamRef	= -1,	kBoundsErr			= -2};OSErr NewStream ( tStreamRef* streamRef, Size blockSize );OSErr DisposeStream ( tStreamRef streamRef );OSErr SetStreamData ( tStreamRef streamRef, Ptr dataPtr, Size dataSize );OSErr GetStreamData ( tStreamRef streamRef, Ptr dataPtr, Size dataSize );OSErr GetStreamDataPtr ( tStreamRef streamRef, Ptr* dataPtr );Size GetStreamDataSize ( tStreamRef streamRef );tStreamCursor GetStreamCursor ( tStreamRef streamRef );OSErr SetStreamCursor ( tStreamRef streamRef, tStreamCursor byteCount );void ResetStreamCursor ( tStreamRef streamRef );OSErr CompactStream ( tStreamRef streamRef );#endif // define __STREAMS__