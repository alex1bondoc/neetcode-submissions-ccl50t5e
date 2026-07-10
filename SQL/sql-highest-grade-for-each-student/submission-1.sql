SELECT student_id, exam_id, score
FROM exam_results a
WHERE score = (
    SELECT MAX(score) 
    FROM exam_results c
    WHERE a.student_id = c.student_id
);