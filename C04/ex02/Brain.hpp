#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
	std::string ideas[100];

	public:
		// Constructors
		Brain();
		Brain(const Brain &copy);
		
		// Destructor
		~Brain();
		
		// Operators
		Brain & operator=(const Brain &assign);

		void	setIdeas(unsigned int index, const std::string idea);
		const	std::string	getIdeas(unsigned int index) const;

};

// source https://github.com/tpsatish95/emotion-detection-from-text/blob/master/datasets/Emotion%20Phrases.csv
// std::string const Brain::ideas[100] =
// 		{
// 			"anger,Insulted by disgusting people.",
// 			"sadness,My friend was badly hurt.",
// 			"disgust,Someone not responding to my criticism.",
// 			"shame,Swearing in public.",
// 			"guilt,Hurt someone's feelings unintentionally.",
// 			"joy,When you told everyone in the last lecture you will do all",
// 			"lectures again in English and everybody can come (not only)",
// 			"English classes)",
// 			"fear,Before an examn.",
// 			"anger,My class leader told me I am not chosen for your English",
// 			"lectures.",
// 			"sadness,Finding out that the university will give first priority"
// 			"qualified practioners and clinical years to go to your English ",
// 			"lectures.",
// 			"disgust,Finding out that old and useless practitioners of retirement age",
// 			"will go to your English lectures and they do not understand",
// 			"English.",
// 			"shame,China cannot give your lectures bigger place and sound system.",
// 			"guilt,I am not good enough for your experiment I am doing.",
// 			"joy,Winning a game after a long time of losing.",
// 			"fear,Almost had a bicycle accident.",
// 			"anger,People not cueing in the dining hall.",
// 			"sadness,Failed an examn.",
// 			"disgust,Saw a real party leader.",
// 			"shame,Failed to recagnize a friend on the street.",
// 			"guilt,Forgot to collect post for a friend.",
// 			"joy,Being chosen to do your experiment with aphasia.",
// 			"fear,You may find out that I am stupid and not to let me do your ",
// 			"experiment.",
// 			"anger,A classmate told me I must have bribed the class leader to let me ",
// 			"go to your English lecture.",
// 			"sadness,I was not chosen for the All English class.",
// 			"disgust,Saw my class leader acting like a God when he chose people to go ",
// 			"to your English lectures.",
// 			"shame,Talking to friends about how old you are and we cannot be as ",
// 			"successful as you at your age.",
// 			"guilt,Telling friends about your nickname.",
// 			"joy,I got better marks in the examn than many arrogant people.",
// 			"fear,Before the examn.",
// 			"anger,Insulted by some stupid people.",
// 			"sadness,Lost a friend.",
// 			"disgust,Hear people talking at my back.",
// 			"shame,Saw something stupid and ignorant happening in the countryside.",
// 			"fear,I was very scared when I went to the examination hall for my M.Sc ",
// 			"examination as I had studied a limited partion of the course ",
// 			"thoroughly and I was in great doubt whether that would be asked.",
// 			"anger,I was most angry when India lost the Triangular Cricket trophy ",
// 			"held in Australia.  I was so angry that I fought (orally) with my ",
// 			"friend.",
// 			"sadness,I was very sad  when I got the XIIth standard results, when I got ",
// 			"low marks as compared to my friend and I could not get admission ",
// 			"to courses like medicine.",
// 			"disgust,I was disgusted at myself when I dropped a vital catch, while ",
// 			"playing a cricket match, and we lost the match; though the catch ",
// 			"was difficult. ",
// 			"shame,There is one thing which makes me feel shameful,  when I see ",
// 			"friends of my age group working and earning a lot, when I am ",
// 			"still studying.  A friend I met a week ago after a period of 5 ",
// 			"years is earning more than Rs 3000/ month.",
// 			"guilt,I felt guilty when I read an advertisement for a job as a chemist ",
// 			"in the newspaper and when my friend asked me if I had applied for ",
// 			"that job, I told him that I had not even seen the paper of that ",
// 			"day.",
// 			"joy,When I got my first unknown compound while doing my M.Sc ",
// 			"research, I was very happy.  This is because my research was based ",
// 			"on this type of reactions and compounds.",
// 			"fear,I was very scared at the time of the Ty.B.Sc examination as I had ",
// 			"decided to get 1st class results.  I was afraid thinking of how ",
// 			"the papers would be.",
// 			"anger,When my neighbours accused my brother of stealing their ",
// 			"rose-bush, I was very angry as he had not touched it at all.",
// 			"sadness,When I heard that my girlfriend was getting married to another ",
// 			"person, I felt very sad.  That day I did not eat anything and ",
// 			"kept thinking of her all day long.",
// 			"disgust,[ No response.]",
// 			"shame,When I had insulted my father two years back, at that time I was ",
// 			"very angry due to some reasons.",
// 			"guilt,I felt very guilty when I tried to teach swimming to my younger ",
// 			"brother, as I myself could not swim very well and my brother ",
// 			"had started sinking to the bottom, however my elder brother ",
// 			"saved him.",
// 			"joy,This happened a year when I was having a hard time, I got ",
// 			"admission to do research despite obstacles in the procedure of admission."
// 			"fear,It was the time when I was in no position to secure a Ist class ",
// 			"in the M.Sc exam and this was likely to affect my career.",
// 			"anger,I missed an opportunity to go abroad because of some silly ",
// 			"mistakes for which I had to suffer a lot.",
// 			"sadness,It was at the time of my M.Sc exam, when I was not in a position ",
// 			"to take the exam after having studied seriously.",
// 			"disgust,When I opted for my research field, for them the percentage of ",
// 			"marks was more important than my knowledge.",
// 			"shame,When I was not in a position to control myself.  I had said too ",
// 			"much and had been cruel with no other than my mother.",
// 			"guilt,Two days after the above incident, I was thinking about my ",
// 			"morally shameful act and I felt sorry for that incident, but it",
// 			"was too late, however I did realize this.",
// 			"joy,When I got the first compound through column.",
// 			"fear,When I did not get the compound which is known",
// 			"anger,When I got low marks in B.Sc final",
// 			"sadness,When my first love was not successful.",
// 			"disgust,[ When mix was coming from column for several days.]"
// 		};

#endif