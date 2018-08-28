#if !defined(ScoreH)
#define ScoreH


class Score {
public:
	Score();

	int getAmount() const;
	void updateAmount(int);
private:
	int amount_;
};

#endif // !defined(NutH)
