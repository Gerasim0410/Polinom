#include "TList.h"

struct TMonom {
	double coeff;
	int px, py, pz;
};

bool operator> (const TMonom& m, const TMonom& n) {
	int f, s;
	if (n.px < -100) return true;
	f = m.px * 100 + m.py * 10 + m.pz;
	s = n.px * 100 + n.py * 10 + n.pz;
	if (f > s)
		return true;
	else
		return false;
}

bool operator< (const TMonom& m, const TMonom& n) {
	int f, s;
	if (m.px < -100) return true;
	f = m.px * 100 + m.py * 10 + m.pz;
	s = n.px * 100 + n.py * 10 + n.pz;
	if (f < s)
		return true;
	else 
		return false;
}

bool operator>= (const TMonom& m, const TMonom& n) {
	return !(m < n);
}

bool operator<= (const TMonom& m, const TMonom& n) {
	return !(m > n);
}

bool operator== (const TMonom& m, const TMonom& n) {
	if (&m == NULL || &n == NULL)
		return false;
	if (m.px == n.px && m.py == n.py && m.pz == n.pz && m.coeff==n.coeff)
		return true;
	else 
		return false;
}

bool operator!= (const TMonom& m, const TMonom& n) {
	return (!(m == n));
}

TMonom operator+(const TMonom& t1, const TMonom& t2) {
	if ((t1.px != t2.px) || (t1.py != t2.py) || (t1.pz != t2.pz)) {
		char *str = "Degrees of these monoms are different";
		throw str;
	}

	TMonom res;

	res.px = t1.px;
	res.py = t1.py;
	res.pz = t1.pz;
	res.coeff = t1.coeff + t2.coeff;

	return res;
}

TMonom operator-(const TMonom& t1, const TMonom& t2) {
	if ((t1.px != t2.px) || (t1.py != t2.py) || (t1.pz != t2.pz)) {
		char *str = "Degrees of these monoms are different";
		throw str;
	}

	TMonom res;

	res.px = t1.px;
	res.py = t1.py;
	res.pz = t1.pz;
	res.coeff = t1.coeff - t2.coeff;

	return res;
}

TMonom operator*(const TMonom& t1, const TMonom& t2) {
	TMonom res;

	res.px = t1.px + t2.px;
	res.py = t1.py + t2.py;
	res.pz = t1.pz + t2.pz;
	res.coeff = t1.coeff * t2.coeff;

	return res;
}

TMonom operator/(const TMonom& t1, const TMonom& t2) {
	TMonom res;

	res.px = t1.px - t2.px;
	res.py = t1.py - t2.py;
	res.pz = t1.pz - t2.pz;
	res.coeff = t1.coeff / t2.coeff;

	return res;
}

TMonom operator*(const TMonom &q, const double a) {
	TMonom res;
	res.coeff = q.coeff * a;
	res.px = q.px;
	res.py = q.py;
	res.pz = q.pz;
	return res;
}

ostream& operator<<(ostream &out, const TMonom &m) {
	out << m.coeff << "x^" << m.px << "y^" << m.py << "z^" << m.pz;
	return out;

}

class TPolinom : public THeadList<TMonom> {
public:
	TPolinom() : THeadList<TMonom>() {
		pHead->val.coeff = 0;
		pHead->val.pz = -1;
	}
	TPolinom(int monoms[][2], int n) :THeadList<TMonom>() {
		pHead->val.coeff = 0;
		pHead->val.px = 0;
		pHead->val.py = 0;
		pHead->val.pz = -1;
		TMonom m;
		for (int i = 0; i < n; i++){
			m.coeff = monoms[i][0];
			m.px = monoms[i][1] / 100;
			m.py = monoms[i][1] / 10 % 10;
			m.pz = monoms[i][1] % 10;
			insOrd(m);
		}
	}

	TPolinom(TMonom *m, int size) : THeadList<TMonom>() {
		pHead->val.coeff = 0;
		pHead->val.pz = -1;

		for (int i = 0; i < size; i++)
			insLast(m[i]);
	}

	TPolinom(TPolinom &q) : THeadList<TMonom>() {
		pHead->val.coeff = 0;
		pHead->val.pz = -1;
		for (q.Reset(); !q.IsEnd(); q.GoNext()) {
			insLast(q.pCurr->val);
		}
	}

	TPolinom& operator=(TPolinom &q) {
		while (size) {
			DelFirst();
		}
		for (q.Reset(); !q.IsEnd(); q.GoNext()) {
			insLast(q.pCurr->val);
		}
		return *this;
	}

	TPolinom operator*(const double a);
	void operator*=(const double a);

	bool operator==(TPolinom &q) {
		if (size == q.size) {
			for (Reset(); !IsEnd(); GoNext()) {
				for (q.Reset(); !q.IsEnd(); q.GoNext()) {
					if (pCurr->val != q.pCurr->val)return false;
				}
			}
			return true;
		}
		else return false;
	}

	bool operator==(TMonom &q) {
		Reset();
		if (size == 1 && pCurr->val == q) {
			return true;
		}
		return false;
	}


	void operator+=(TPolinom &q);
	TPolinom operator+(TPolinom &q);
	void operator-=(TPolinom &q);
	TPolinom operator-(TPolinom &q);
	void operator*=(TMonom &m);
	TPolinom operator*(TMonom &m);
	TPolinom operator*(TPolinom &q);

	bool isStart() { return pCurr == pFirst; }
	double getCoeff() { return pCurr->val.coeff; }
	int px() { return pCurr->val.px; }
	int py() { return pCurr->val.py; }
	int pz() { return pCurr->val.pz; }
	bool isEmpty() { return pFirst == NULL; }

	void insOrd(const TMonom &m);
	//string GetString();

	friend ostream& operator<<(ostream &out, TPolinom &p) {
		if (p.size) {
			for (p.Reset(); !p.IsEnd(); p.GoNext()) {
				out << p.pCurr->val << " + ";
			}
			out << ".";
		}
		return out;
	}
};

void TPolinom::operator*=(const double a) {
	if (size) {
		for (Reset(); !IsEnd(); GoNext())
			pCurr->val.coeff *= a;
	}
}

TPolinom TPolinom::operator*(const double a) {
	TPolinom res;
	res += *this;
	res *= a;
	return res;
}

TPolinom TPolinom::operator*(TMonom &m) {
	TPolinom res;
	res += *this;
	res *= m;
	return res;
}

void TPolinom::operator+=(TPolinom &q) {
	if (size && q.size) {
		TMonom pm, qm, rm;
		Reset();
		q.Reset();
		while (!q.IsEnd())
		{
			pm = pCurr->val;
			qm = q.pCurr->val;
			if (pm.coeff != NULL && pm > qm)
			{
				GoNext();
			}
			else
			{
				if (pm < qm)
				{
					insCurrent(qm);
					q.GoNext();
				}
				else {
					rm = pm;
					rm.coeff += qm.coeff;
					if (rm.coeff == 0)
					{
						DelCurrent();
						q.GoNext();
					}
					else
					{
						pCurr->val = rm;
						if (&q == this) {
							GoNext();
						}
						else
						{
							GoNext();
							q.GoNext();
						}
					}
				}
			}
		}
	}	
	else if (!size && q.size) *this = q;
}

TPolinom TPolinom::operator+(TPolinom &q) {
	TPolinom res;
	res += *this;
	res += q;
	return res;
}

void TPolinom::operator-=(TPolinom &q) {
	if (!q.size)
		return;
	q *= -1;
	*this += q;
}

TPolinom TPolinom::operator-(TPolinom &q) {
	return *this + (q * (-1));
}

void TPolinom::operator*=(TMonom &m) {
	for (Reset(); !IsEnd(); GoNext())
		pCurr->val = pCurr->val * m;
}

TPolinom TPolinom::operator*(TPolinom &q) {
	TPolinom res;
	q.Reset();
	for (q.Reset(); !q.IsEnd(); q.GoNext()) {
		TPolinom tmp = *this;
		res += tmp * q.pCurr->val;
	}

	return res;
}

void TPolinom::insOrd(const TMonom &m) {
	if (m.coeff == 0)
		return;
	if (!size) {
		insFirst(m);
		return;
	}
	for (Reset(); !IsEnd(); GoNext()) {
		if (pCurr->val == m) {
			pCurr->val.coeff += m.coeff;
			if (pCurr->val.coeff == 0)
				DelCurrent();
			return;
		}
		if (pCurr->val < m) {
			insCurrent(m);
			return;
		}
	}
	insLast(m);
}

/*string TPolinom::GetString() {
	if (isEmpty())
		return "0";
	string tmp = "";
	for (Reset(); !IsEnd(); GoNext()) {
		if (!isStart() && getCoeff() > 0)
			tmp += "+";
		if ((getCoeff() != 1) || (!px() && !py() && !pz()))
			tmp += getCoeff();
		if (px())
			if (px() > 1) {
				tmp += "x^";
				tmp += px();
			}
			else
				tmp += "x";
		if (py())
			if (py() > 1) {
				tmp += "y^";
				tmp += py();
			}
			else
				tmp += "y";
		if (pz())
			if (pz() > 1) {
				tmp += "z^";
				tmp += pz();
			}
			else
				tmp += "z";
	}
	return tmp;
}*/
