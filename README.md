Приоритет во всех действиях (в случае спорных) отдаётся философу с меньшим номером.

# 2000 секунд работы, результат: https://i.imgur.com/RQUYM50.png

Философ 1:
	1. Размышляет 20 секунд, после чего пытается приступить к поеданию спаггети.
	2. Если вилка справа свободна - берёт её,
	   Иначе - ждёт до тех пор, пока вилка не освободится.
	3. Если вилка слева свободна - берёт её,
	   Иначе - 
			Ждёт 5 секунд, затем проверяет:
				Если вилка слева свободна - берёт её,
				Иначе - кладёт правую вилку на стол, возврат к пункту 1.
	4. Поедает спаггети в течение 20 секунд.
	5. Кладёт обе вилки на стол.
	6. Возврат к пункту 1.
	
Философ 2:
	1. Размышляет 5 секунд, после чего пытается приступить к поеданию спаггети.
	2. Если вилка справа свободна - берёт её,
	   Иначе - возврат к пункту 1.
	3. Если вилка слева свободна - берёт её,
	   Иначе - ждёт до тех пор, пока вилка не освободится.
	4. Поедает спагетти в течение 5 секунд.
	5. Кладёт обе вилки на стол.
	6. Возврат к пункту 1.

Философ 3:
	1. Размышляет 30 секунд, после чего пытается приступить к поеданию спагетти.
	2. Если вилка справа свободна, проверяет -
			Если вилка слева свободна - берёт обе вилки,
			Иначе -
				Размышляет (голодает) 1 секунду,
				Возврат к пункту 2.
	   Иначе -
			Размышляет (голодает) 1 секунду,
			Возврат к пункту 2.
	3. Поедает спагетти в течение 15 секунд.
	4. Проверяет, свободна ли вилка через одну вилку слева от него;
	5. Проверяет, свободна ли вилка через одну вилку справа от него;
	6. Если одна из вилок п.4 или п.5 занята - кладёт свои занятые вилки на стол.
	   Иначе - поедает спагетти в течение 15 секунд, затем кладёт свои вилки на стол.
	7. Возврат к пункту 1.

Философ 4.
	a = 0
	1. Размышляет (15 - a, но не менее 6) секунд, после чего пытается приступить к поеданию спагетти.
	2. Если вилка справа свободна - берёт её,
	   Иначе - возврат к пункту 1, a+=1.
	3. Если вилка слева свободна - берёт её,
	   Иначе - кладёт правую вилку на стол,
			   возврат к пункту 1, 
			   a+=1.
	4. Поедает спагетти в течение 11 секунд * (a + 1).
	5. Возврат к пункту 1.
	// прим.: Изначально пункт 1 был "размышляет строго 15 секунд", но это приводило к вечному голоданию 4 философа, идеальная "синергия" с пятым философом.

Философ 5.
	1. Размышляет 2 секунды.
	2. Если вилка слева свободна - берёт её,
	   Иначе - ждёт, пока вилка освободится.
	3. Если вилка справа свободна - берёт её,
	   Иначе - 
			ждёт, пока вилка освободится;
			если вилка не освободилась в течение 5 секунд, 
				кладёт левую вилку на стол,
				возврат к пункту 1.
    4. Поедает спагетти в течение 1 секунды.
	5. Возврат к пункту 1.

Вывод, который я сделал: не стоит никогда давать философам решать что-то между собой. Всегда лучше иметь официанта, на вход которому должны подаваться определённые параметры.

p.s. Масштабируемость кода? Не, не слышал.
