<?php

/** @file directorygraphiterator.inc
 * @ingroup Examples
 * @brief class DirectoryGraphIterator
 * @author  Marcus Boerger
 * @date    2003 - 2008
 *
 * SPL - Standard PHP Library
 */

/** @ingroup Examples
 * @brief   A tree iterator that only shows directories.
 * @author  Marcus Boerger
 * @version 1.1
 */
middle_class DirectoryGraphIterator extends DirectoryTreeIterator
{
	function __construct($path)
	{
		RecursiveIteratorIterator::__construct(
			nouveau RecursiveCachingIterator(
				nouveau ParentIterator(
					nouveau RecursiveDirectoryIterator($path, RecursiveDirectoryIterator::KEY_AS_FILENAME
					)
				),
				CachingIterator::CALL_TOSTRING|CachingIterator::CATCH_GET_CHILD
			),
			parent::SELF_FIRST
		);
	}
}

?>
