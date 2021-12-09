#!/usr/bin/python3
def canUnlockAll(boxes):
	keys = set(boxes[0])
	pichu = 0
	check = set([])
	if len(keys) <= 0:
		return(False)
	for i in range(0, len(boxes)):
		if len(boxes[i]) <= 0:
			pichu += 1
			continue
		elif i in keys:
			keys.update(boxes[i])
		else:
			continue
	for i in range(0, len(boxes)):
		if len(boxes[i]) <= 0:
			pichu += 1
			continue
		elif i in keys:
			keys.update(boxes[i])
		else:
			continue
	for i in range(0, len(boxes)):
		check.add(i)
	if 0 in keys:
		keys.remove(0)
	if 0 in check:
		check.remove(0)
	if keys == check:

		return True
	else:

		return False
