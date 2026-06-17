def grade(score: int) -> chr:
    return 'A' if(score >= 90) else 'B' if(score >= 80 and score < 90) else 'C' if(score >= 70 and score < 80) else 'F'
    
result = grade(95)
print(result)