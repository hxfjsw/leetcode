#601. 体育馆的人流量

#X 市建了一个新的体育馆，
# 每日人流量信息被记录在这三列信息中：序号 (id)、日期 (date)、 人流量 (people)。
# 请编写一个查询语句，找出高峰期时段，要求连续三天及以上，并且每天人流量均不少于100。
# 例如，表 1：
# +------+------------+-----------+
# | id   | date       | people    |
# +------+------------+-----------+
# | 1    | 2017-01-01 | 10        |
# | 2    | 2017-01-02 | 109       |
# | 3    | 2017-01-03 | 150       |
# | 4    | 2017-01-04 | 99        |
# | 5    | 2017-01-05 | 145       |
# | 6    | 2017-01-06 | 1455      |
# | 7    | 2017-01-07 | 199       |
# | 8    | 2017-01-08 | 188       |
# +------+------------+-----------+

# 对于上面的示例数据，输出为：
# +------+------------+-----------+
# | id   | date       | people    |
# +------+------------+-----------+
# | 5    | 2017-01-05 | 145       |
# | 6    | 2017-01-06 | 1455      |
# | 7    | 2017-01-07 | 199       |
# | 8    | 2017-01-08 | 188       |
# +------+------------+-----------+


select
    distinct a.id, a.date, a.people
from
    stadium a, stadium b, stadium c
where
            (
                            a.id = b.id - 1 && a.id = c.id - 2 ||
                            a.id = b.id + 1 && a.id = c.id - 1 ||
                            a.id = b.id + 1 && a.id = c.id + 2
                )
            and a.people >= 100 && b.people >= 100 && c.people >= 100
order by
    a.id
;
